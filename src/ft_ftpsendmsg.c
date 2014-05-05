#include "ft_ftp.h"
#include "ft_common.h"

t_ftpmsg	*ft_ftpsendmsg(t_ftp *ftp, char *cmd, char *content)
{
	if (ftp->sock_cmd != -1)
	{
		if (cmd)
		{
			ft_putstr_fd(cmd, ftp->sock_cmd);
			if (content)
			{
				ft_putchar_fd(' ', ftp->sock_cmd);
				ft_putstr_fd(content, ftp->sock_cmd);
			}
			ft_putnstr_fd("\r\n", ftp->sock_cmd, 2);
		}
		return (ft_ftpreadmsg(ftp));
	}
	return (NULL);
}
