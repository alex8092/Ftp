#include "ft_ftp.h"
#include "ft_common.h"
#include <stdlib.h>

t_ftp	*ft_ftpcreate(void)
{
	t_ftp	*ftp;

	ftp = ft_memalloc(sizeof(t_ftp));
	if (!ftp)
		return (NULL);
	ftp->port = 21;
	ftp->sock_cmd = -1;
	ftp->host = "127.0.0.1";
	return (ftp);
}
