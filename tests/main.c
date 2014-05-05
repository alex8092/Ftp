#include "ft_ftp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	t_ftp	*ftp;
	t_ftpmsg	*msg;
	int		res;
	
	ftp = ft_ftpcreate();
	ftp->host = "192.168.1.17";
	ftp->user = "amerle";
	ftp->pass = "Y3kB4vX2Au25bTp7";
	if ((res = ft_ftpconnect(ftp)) < 0)
	{
		if (res == FTP_NETWORK_ERROR)
			printf("Network error\n");
		else if (res == FTP_LOGIN_ERROR)
			printf("Login error\n");
		return (1);
	}
	msg = ft_ftpgetsys(ftp);
	write(1, msg->msg, msg->len_msg);
	write(1, "\n", 1);
	ft_ftpgetfeat(ftp);
	close(ftp->sock_cmd);
	free(ftp);
	return (0);
}
