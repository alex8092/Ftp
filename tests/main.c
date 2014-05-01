#include "ft_ftp.h"
#include <stdlib.h>

int	main(void)
{
	t_ftp	*ftp;
	ssize_t	ret;
	char	buf[1024];
	
	ftp = ft_ftpcreate();
	ftp->host = "212.27.63.3";
	if (ft_ftpconnect(ftp) < 0)
		perror("test");
	if ((ret = read(ftp->sock_cmd, buf, 1023)) > 0)
		write(1, buf, ret);
	close(ftp->sock_cmd);
	free(ftp);
	return (0);
}
