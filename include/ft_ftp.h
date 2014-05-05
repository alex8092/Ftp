#ifndef FT_FTP_H
# define FT_FTP_H

# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>

# define FTP_NETWORK_ERROR		-2
# define FTP_LOGIN_ERROR		-3

typedef struct s_ftp	t_ftp;
typedef struct s_ftpmsg	t_ftpmsg;

struct					s_ftp
{
	int					port;
	int					sock_cmd;
	const char			*host;
	char				*user;
	char				*pass;
	struct sockaddr_in	sin;
};

struct 					s_ftpmsg
{
	int					code;
	char				*msg;
	size_t				len_msg;
};

int			ft_ftpconnect(t_ftp *ftp);
t_ftp		*ft_ftpcreate(void);
t_ftpmsg	*ft_ftpreadmsg(t_ftp *ftp);
t_ftpmsg	*ft_ftpsendmsg(t_ftp *ftp, char *cmd, char *content);
t_ftpmsg	*ft_ftpgetsys(t_ftp *ftp);
void		ft_ftpgetfeat(t_ftp *ftp);

#endif
