#include "ft_ftp.h"
#include "ft_common.h"
#include <unistd.h>

static int	check_connect(t_ftpmsg *msg)
{
	if (msg && msg->code == 230)
		return (0);
	return (FTP_LOGIN_ERROR);
}

static int	connect_to_server(t_ftp *ftp)
{
	t_ftpmsg	*msg;

	if ((msg = ft_ftpreadmsg(ftp)))
	{
		if (msg->code != 220)
			return (FTP_NETWORK_ERROR);
		if ((msg = ft_ftpsendmsg(ftp, "USER", ftp->user)))
			return (check_connect(ft_ftpsendmsg(ftp, "PASS", ftp->pass)));
		else
			return (FTP_LOGIN_ERROR);
	}
	return (FTP_NETWORK_ERROR);
}

int			ft_ftpconnect(t_ftp *ftp)
{
	int	res;

	if ((ftp->sock_cmd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (-1);
	ftp->sin.sin_addr.s_addr = inet_addr(ftp->host);
	ftp->sin.sin_port = htons(ftp->port);
	ftp->sin.sin_family = AF_INET;
	res = connect(ftp->sock_cmd, (struct sockaddr*)&ftp->sin, sizeof(ftp->sin));
	if (res == -1 || (res = connect_to_server(ftp)) < 0)
	{
		close(ftp->sock_cmd);
		if (res == -1)
			return (FTP_NETWORK_ERROR);
		else
			return (res);
	}
	return (0);
}
