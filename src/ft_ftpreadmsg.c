#include "ft_ftp.h"
#include "ft_common.h"

t_ftpmsg	*ft_ftpreadmsg(t_ftp *ftp)
{
	static t_ftpmsg		msg = { 0 };
	char				*line = NULL;

	if (ft_getnextline(ftp->sock_cmd, &line) > 0 && line)
	{
		if (ft_isnum(line[0]) && ft_isnum(line[1]) && ft_isnum(line[2]))
		{
			line[3] = 0;
			msg.code = ft_atoi(line);
			msg.msg = line + 4;
			msg.len_msg = ft_strlen(msg.msg);
		}
		else if (line[0] == ' ')
		{
			msg.code = 0;
			msg.msg = line + 1;
			msg.len_msg = ft_strlen(line + 1);
		}
		return (&msg);
	}
	return (NULL);
}
