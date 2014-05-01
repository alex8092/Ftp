#include "ft_ftp.h"

int	ft_ftpconnect(t_ftp *ftp)
{
	int	res;

	if ((ftp->sock_cmd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (-1);
	ftp->sin.sin_addr.s_addr = inet_addr(ftp->host);
	ftp->sin.sin_port = htons(ftp->port);
	ftp->sin.sin_family = AF_INET;
	res = connect(ftp->sock_cmd, (struct sockaddr*)&ftp->sin, sizeof(ftp->sin));
	if (res == -1)
	{
		close(ftp->sock_cmd);
		return (-2);
	}
	return (0);
}
