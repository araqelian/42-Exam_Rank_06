# 📌 mini_serv &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;subject.en.txt
<p>
Assignment &nbsp;name&nbsp;&nbsp; : &nbsp;mini_serv<br>
Expected &nbsp;files&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: &nbsp;mini_serv.c<br>
Allowed &nbsp;functions &nbsp;&nbsp;: &nbsp;write, &nbsp;close, &nbsp;select, &nbsp;socket, &nbsp;accept, &nbsp;listen, &nbsp;send, &nbsp;recv, &nbsp;bind, &nbsp;strstr, &nbsp;malloc, &nbsp;realloc, &nbsp;free, &nbsp;calloc, &nbsp;bzero, &nbsp;atoi, &nbsp;sprintf, &nbsp;strlen, &nbsp;exit, &nbsp;strcpy, &nbsp;strcat, &nbsp;memset<br>
-------------------------------------------------------------------------------------------------------------------------------------------
</p>
<p>
Write &nbsp;a &nbsp;program &nbsp;that &nbsp;will &nbsp;listen &nbsp;for &nbsp;client &nbsp;to &nbsp;connect &nbsp;on &nbsp;a &nbsp;certain &nbsp;port &nbsp;on &nbsp;127.0.0.1 &nbsp;and &nbsp;will &nbsp;let &nbsp;clients &nbsp;to &nbsp;speak &nbsp;with &nbsp;each &nbsp;other <br><br>

This &nbsp;program &nbsp;will &nbsp;take &nbsp;as &nbsp;first &nbsp;argument &nbsp;the &nbsp;port &nbsp;to &nbsp;bind &nbsp;to <br>
If &nbsp;no &nbsp;argument &nbsp;is &nbsp;given, &nbsp;it &nbsp;should &nbsp;write &nbsp;in &nbsp;stderr &nbsp;<b>"Wrong &nbsp;number &nbsp;of &nbsp;arguments"</b> &nbsp;followed &nbsp;by &nbsp;a &nbsp;<b>\n</b> &nbsp;and &nbsp;exit &nbsp;with &nbsp;status &nbsp;<b>1</b> <br>
If &nbsp;a &nbsp;System &nbsp;Calls &nbsp;returns &nbsp;an &nbsp;error &nbsp;before &nbsp;the &nbsp;program &nbsp;start &nbsp;accepting &nbsp;connection, &nbsp;it &nbsp;should &nbsp;write &nbsp;in &nbsp;stderr &nbsp;<b>"Fatal &nbsp;error"</b> &nbsp;followed &nbsp;by &nbsp;a &nbsp;<b>\n</b> &nbsp;and &nbsp;exit &nbsp;with &nbsp;status &nbsp;<b>1</b> <br>
If &nbsp;you &nbsp;cant &nbsp;allocate &nbsp;memory &nbsp;it &nbsp;should &nbsp;write &nbsp;in &nbsp;stderr &nbsp;<b>"Fatal &nbsp;error"</b> &nbsp;followed &nbsp;by &nbsp;a &nbsp;<b>\n</b> &nbsp;and &nbsp;exit &nbsp;with &nbsp;status &nbsp;<b>1</b> <br><br>

Your &nbsp;program &nbsp;must &nbsp;be &nbsp;non-blocking &nbsp;but &nbsp;client &nbsp;can &nbsp;be &nbsp;lazy &nbsp;and &nbsp;if &nbsp;they &nbsp;don't &nbsp;read &nbsp;your &nbsp;message &nbsp;you &nbsp;must &nbsp;NOT &nbsp;disconnect &nbsp;them... <br><br>

Your &nbsp;program &nbsp;must &nbsp;not &nbsp;contains &nbsp;<b>#define</b> &nbsp;preproc <br>
Your &nbsp;program &nbsp;must &nbsp;only &nbsp;listen &nbsp;to &nbsp;<b>127.0.0.1</b> <br>
The &nbsp;fd &nbsp;that &nbsp;you &nbsp;will &nbsp;receive &nbsp;will &nbsp;already &nbsp;be &nbsp;set &nbsp;to &nbsp;make &nbsp;'<b>recv</b>' &nbsp;or &nbsp;'<b>send</b>' &nbsp;to &nbsp;block &nbsp;if &nbsp;select &nbsp;hasn't &nbsp;be &nbsp;called &nbsp;before &nbsp;calling &nbsp;them, &nbsp;but &nbsp;will &nbsp;not &nbsp;block &nbsp;otherwise. <br><br>

When &nbsp;a &nbsp;client &nbsp;connect &nbsp;to &nbsp;the &nbsp;server: <br>
<b>-</b> &nbsp;the &nbsp;client &nbsp;will &nbsp;be &nbsp;given &nbsp;an &nbsp;id. &nbsp;the &nbsp;first &nbsp;client &nbsp;will &nbsp;receive &nbsp;the &nbsp;id &nbsp;<b>0</b> &nbsp;and &nbsp;each &nbsp;new &nbsp;client &nbsp;will &nbsp;received &nbsp;the &nbsp;last &nbsp;client &nbsp;id &nbsp;+ &nbsp;1 <br>
<b>-</b> &nbsp;<b>%d</b> &nbsp;will &nbsp;be &nbsp;replace &nbsp;by &nbsp;this &nbsp;number <br>
<b>-</b> &nbsp;a &nbsp;message &nbsp;is &nbsp;sent &nbsp;to &nbsp;all &nbsp;the &nbsp;client &nbsp;that &nbsp;was &nbsp;connected &nbsp;to &nbsp;the &nbsp;server: &nbsp;<b>"server: &nbsp;client &nbsp;%d &nbsp;just &nbsp;arrived\n"</b> <br><br>

clients &nbsp;must &nbsp;be &nbsp;able &nbsp;to &nbsp;send &nbsp;messages &nbsp;to &nbsp;your &nbsp;program. <br>
<b>-</b> &nbsp;message &nbsp;will &nbsp;only &nbsp;be &nbsp;printable &nbsp;characters, &nbsp;no &nbsp;need &nbsp;to &nbsp;check <br>
<b>-</b> &nbsp;a &nbsp;single &nbsp;message &nbsp;can &nbsp;contains &nbsp;multiple &nbsp;<b>\n</b> <br>
<b>-</b> &nbsp;when &nbsp;the &nbsp;server &nbsp;receive &nbsp;a &nbsp;message, &nbsp;it &nbsp;must &nbsp;resend &nbsp;it &nbsp;to &nbsp;all &nbsp;the &nbsp;other &nbsp;client &nbsp;with &nbsp;<b>"client &nbsp;%d: &nbsp;"</b> &nbsp;before &nbsp;every &nbsp;line! <br><br>

When &nbsp;a &nbsp;client &nbsp;disconnect &nbsp;from &nbsp;the &nbsp;server: <br>
<b>-</b> &nbsp;a &nbsp;message &nbsp;is &nbsp;sent &nbsp;to &nbsp;all &nbsp;the &nbsp;client &nbsp;that &nbsp;was &nbsp;connected &nbsp;to &nbsp;the &nbsp;server: &nbsp;<b>"server: &nbsp;client &nbsp;%d &nbsp;just &nbsp;left\n"</b> <br><br>

Memory &nbsp;or &nbsp;fd &nbsp;leaks &nbsp;are &nbsp;forbidden <br><br>

To &nbsp;help &nbsp;you, &nbsp;you &nbsp;will &nbsp;find &nbsp;the &nbsp;file &nbsp;main.c &nbsp;with &nbsp;the &nbsp;beginning &nbsp;of &nbsp;a &nbsp;server &nbsp;and &nbsp;maybe &nbsp;some &nbsp;useful &nbsp;functions. &nbsp;(Beware &nbsp;this &nbsp;file &nbsp;use &nbsp;forbidden &nbsp;functions &nbsp;or &nbsp;write &nbsp;things &nbsp;that &nbsp;must &nbsp;not &nbsp;be &nbsp;there &nbsp;in &nbsp;your &nbsp;final &nbsp;program) <br><br>

Warning &nbsp;our &nbsp;tester &nbsp;is &nbsp;expecting &nbsp;that &nbsp;you &nbsp;send &nbsp;the &nbsp;messages &nbsp;as &nbsp;fast &nbsp;as &nbsp;you &nbsp;can. &nbsp;Don't &nbsp;do &nbsp;un-necessary &nbsp;buffer. <br><br>

Evaluation &nbsp;can &nbsp;be &nbsp;a &nbsp;bit &nbsp;longer &nbsp;than &nbsp;usual... <br><br>

Hint: &nbsp;you &nbsp;can &nbsp;use &nbsp;nc &nbsp;to &nbsp;test &nbsp;your &nbsp;program <br>
Hint: &nbsp;you &nbsp;should &nbsp;use &nbsp;nc &nbsp;to &nbsp;test &nbsp;your &nbsp;program <br>
Hint: &nbsp;To &nbsp;test &nbsp;you &nbsp;can &nbsp;use &nbsp;fcntl(fd, &nbsp;F_SETFL, &nbsp;O_NONBLOCK) &nbsp;but &nbsp;use &nbsp;select &nbsp;and &nbsp;NEVER &nbsp;check &nbsp;EAGAIN &nbsp;(man &nbsp;2 &nbsp;send) <br>
</p>
