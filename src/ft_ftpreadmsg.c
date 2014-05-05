#include "ft_ftp.h"
#include "ft_common.h"

t_ftpmsg	*ft_ftpreadmsg(t_ftp *ftp)
{
	static t_ftpmsg		msg = { 0 };
	char				*line = NULL;

	if (ft_getnextline(ftp->sock_cmd, &line) > 0 && line)
	{
		msg.len_msg = strlen(line);
		msg.msg = line;
		return (&msg);
	}
	return (NULL);
}
