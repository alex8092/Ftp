#include "ft_ftp.h"
#include <stdlib.h>

int	main(void)
{
	t_ftp	*ftp;
	
	ftp = ft_ftpcreate();
	free(ftp);
	return (0);
}
