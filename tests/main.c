#include "ft_ftp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	t_ftp	*ftp;
	t_ftpmsg	*msg;
	
	ftp = ft_ftpcreate();
	ftp->host = "212.27.63.3";
	if (ft_ftpconnect(ftp) < 0)
		return (-1);
	if ((msg = ft_ftpreadmsg(ftp)))
		write(1, msg->msg, msg->len_msg);
	close(ftp->sock_cmd);
	free(ftp);
	return (0);
}
