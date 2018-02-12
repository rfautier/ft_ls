/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:39:50 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 18:43:34 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	grppro(t_struct *s_list, int i, struct stat s_filestat)
{
	struct passwd	*p;
	struct group	*grp;

	if (!(p = getpwuid(s_filestat.st_uid)))
	{
		s_list[i].proprio = ft_itoa(s_filestat.st_uid);
		s_list[i].itoapro = 1;
	}
	else
	{
		s_list[i].proprio = p->pw_name;
		s_list[i].itoapro = 0;
	}
	if (!(grp = getgrgid(s_filestat.st_gid)))
	{
		s_list[i].groupe = ft_itoa(s_filestat.st_gid);
		s_list[i].itoagrp = 1;
	}
	else
	{
		s_list[i].groupe = grp->gr_name;
		s_list[i].itoagrp = 0;
	}
}

char	*lmode2(char *mode, char *str)
{
	struct stat s_filestat;

	lstat(str, &s_filestat);
	mode[1] = (s_filestat.st_mode & S_IRUSR) ? 'r' : '-';
	mode[2] = (s_filestat.st_mode & S_IWUSR) ? 'w' : '-';
	mode[3] = (s_filestat.st_mode & S_IXUSR) ? 'x' : '-';
	mode[4] = (s_filestat.st_mode & S_IRGRP) ? 'r' : '-';
	mode[5] = (s_filestat.st_mode & S_IWGRP) ? 'w' : '-';
	mode[6] = (s_filestat.st_mode & S_IXGRP) ? 'x' : '-';
	mode[7] = (s_filestat.st_mode & S_IROTH) ? 'r' : '-';
	mode[8] = (s_filestat.st_mode & S_IWOTH) ? 'w' : '-';
	mode[9] = (s_filestat.st_mode & S_IXOTH) ? 'x' : '-';
	mode[10] = '\0';
	return (mode);
}

void	our_stat2(t_struct *s_list, int i, char *str)
{
	char		buf[256];
	struct stat	s_filestat;

	lstat(str, &s_filestat);
	if (s_list[i].mode[0] == 'l')
	{
		readlink(str, buf, 256);
		s_list[i].namesymb = ft_strdup(buf);
	}
	if (s_list[i].mode[0] == 'c' || s_list[i].mode[0] == 'b')
	{
		s_list[i].major = major(s_filestat.st_rdev);
		s_list[i].minor = minor(s_filestat.st_rdev);
	}
}

void	modif_time2(char *tmp, char *real)
{
	real[0] = tmp[4];
	real[1] = tmp[5];
	real[2] = tmp[6];
	real[3] = tmp[7];
	real[4] = tmp[8];
	real[5] = tmp[9];
	real[6] = tmp[10];
}

void	modif_time3(char *tmp, char *real)
{
	real[7] = tmp[11];
	real[8] = tmp[12];
	real[9] = tmp[13];
	real[10] = tmp[14];
	real[11] = tmp[15];
	real[12] = '\0';
}
