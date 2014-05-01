#ifndef FT_FTP_H
# define FT_FTP_H

typedef struct s_ftp	t_ftp;

struct		s_ftp
{
	int		port;
	int		sock_cmd;
};

t_ftp	*ft_ftpcreate(void);

#endif
