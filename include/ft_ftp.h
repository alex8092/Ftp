#ifndef FT_FTP_H
# define FT_FTP_H

# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct s_ftp	t_ftp;

struct		s_ftp
{
	int					port;
	int					sock_cmd;
	const char			*host;
	struct sockaddr_in	sin;
};

int		ft_ftpconnect(t_ftp *ftp);
t_ftp	*ft_ftpcreate(void);

#endif
