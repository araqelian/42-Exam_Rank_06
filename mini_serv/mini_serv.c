#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

int		sockfd, maxfd, id;
fd_set	aset, rset, wset;
int		arr[65000];
char	buff[200200];





void	print_error_and_exit(const char* error_msg)
{
	if (sockfd > 2)
		close(sockfd);
	write(2, error_msg, strlen(error_msg));
	exit(1);
}


void	send_all_users(const int user_fd)
{
	for (int fd = 2; fd <= maxfd; ++fd)
	{
		if (fd != user_fd && FD_ISSET(fd, &wset))
		{
			if (send(fd, buff, strlen(buff), 0) < 0)
				print_error_and_exit("Fatal error\n");
		}
	}
}


int main(int argc, char** argv)
{
	if (argc != 2)
		print_error_and_exit("Wrong number of arguments\n");

	struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		print_error_and_exit("Fatal error\n");

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		print_error_and_exit("Fatal error\n");

	if (listen(sockfd, 10) != 0)
		print_error_and_exit("Fatal error\n");

	socklen_t	len = sizeof(cli);
	id = 0;
	int	connfd = 0;
	maxfd = sockfd;
	FD_ZERO(&aset);
	FD_SET(sockfd, &aset);


	while (42)
	{
		rset = wset = aset;

		if (select(maxfd + 1, &rset, &wset, 0, 0) < 0)
			continue;

		if (FD_ISSET(sockfd, &rset))
		{
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0)
				print_error_and_exit("Fatal error\n");

			sprintf(buff, "server: client %d just arrived\n", id);
			FD_SET(connfd, &aset);
			arr[connfd] = id++;
			send_all_users(connfd);
			maxfd = (maxfd > connfd) ? maxfd : connfd;
			continue;
		}

		for (int fd = 2; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &rset))
			{
				ssize_t	r = 1;
				char	user_msg[200200];

				bzero(&user_msg, sizeof(user_msg));

				while (r == 1 && user_msg[strlen(user_msg) - 1] != '\n')
					r = recv(fd, user_msg + strlen(user_msg), 1, 0);

				if (r <= 0)
				{
					sprintf(buff, "server: client %d just left\n", arr[fd]);
					FD_CLR(fd, &aset);
					close(fd);
				}
				else
					sprintf(buff, "client %d: %s", arr[fd], user_msg);
				send_all_users(fd);
			}
		}
	}
	return 0;
}
