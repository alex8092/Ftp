#include "ft_ftp.h"
#include "ft_common.h"

t_ftpmsg	*ft_ftpreadmsg(t_ftp *ftp)
{
	static t_ftpmsg		msg = { 0 };
	static char			line[1025];
	ssize_t				ret;

	if ((ret = read(ftp->sock_cmd, line, 1024)) > 0)
	{
		line[ret] = 0;
		if (ft_isnum(line[0]) && ft_isnum(line[1]) && ft_isnum(line[2]))
		{
			line[3] = 0;
			if (msg.msg)
				free(msg.msg);
			msg.code = ft_atoi(line);
			msg.msg = line + 4;
			msg.len_msg = ft_strlen(msg.msg);
			return (&msg);
		}
	}
	return (NULL);
}
