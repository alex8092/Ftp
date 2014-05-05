#include "ft_ftp.h"

void	ft_ftpgetfeat(t_ftp *ftp)
{
	t_ftpmsg	*msg;

	if ((msg = ft_ftpsendmsg(ftp, "FEAT", NULL)) && msg->code == 211)
	{
		printf("msg : %s\n", msg->msg);
		while ((msg = ft_ftpreadmsg(ftp)) && msg->code != 211)
		{
			printf("feature : %s\n", msg->msg);
		}
		printf("msg : %s\n", msg->msg);
	}
}
