#include "ft_ftp.h"

t_ftpmsg	*ft_ftpgetsys(t_ftp *ftp)
{
	return (ft_ftpsendmsg(ftp, "SYST", NULL));
}
