/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:53:36 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 11:35:24 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*lmode(char *str)
{
	struct stat	s_filestat;
	char		*mode;

	if (!(mode = malloc(sizeof(char) * 11)))
		exit(0);
	lstat(str, &s_filestat);
	mode[0] = (S_ISDIR(s_filestat.st_mode)) ? 'd' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISLNK(s_filestat.st_mode)) ? 'l' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISREG(s_filestat.st_mode)) ? '-' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISSOCK(s_filestat.st_mode)) ? 's' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISFIFO(s_filestat.st_mode)) ? 'f' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISBLK(s_filestat.st_mode)) ? 'b' : '0';
	if (mode[0] == '0')
		mode[0] = (S_ISCHR(s_filestat.st_mode)) ? 'c' : '0';
	mode = lmode2(mode, str);
	return (mode);
}

void		our_stat(char *str, t_struct *s_list, int i)
{
	struct stat		s_filestat;
	char			*real;

	if (!(real = malloc(sizeof(char) * 13)))
		exit(0);
	if ((lstat(str, &s_filestat) == -1))
	{
		initialisation(s_list, i);
		return ;
	}
	s_list[i].modif = modif_time(str, real);
	s_list[i].nbrlien = s_filestat.st_nlink;
	grppro(s_list, i, s_filestat);
	s_list[i].taille = s_filestat.st_size;
	s_list[i].mode = lmode(str);
	our_stat2(s_list, i, str);
	s_list[i].time = s_filestat.st_mtime;
	s_list[i].blocks = s_filestat.st_blocks;
}

char		*modif_time(char *str, char *real)
{
	struct stat	s_filestat;
	char		*tmp;
	char		*annee;

	lstat(str, &s_filestat);
	tmp = ctime(&s_filestat.st_mtime);
	modif_time2(tmp, real);
	if ((s_filestat.st_mtime < time(NULL) - 15778800) ||
			s_filestat.st_mtime > time(NULL) + 15778800)
	{
		if (s_filestat.st_mtime < time(NULL) - 15778800)
			annee = ft_itoa((s_filestat.st_mtime / 31536000) + 1970);
		else
			annee = ft_itoa((s_filestat.st_mtime / 31536000) + 1970);
		real[7] = ' ';
		real[8] = annee[0];
		real[9] = annee[1];
		real[10] = annee[2];
		real[11] = annee[3];
		real[12] = '\0';
		free(annee);
	}
	else
		modif_time3(tmp, real);
	return (real);
}

t_struct	*list(char *str, int nbrfile, DIR *dp, char *name)
{
	struct dirent	*lol;
	int				i;
	char			*path;
	char			*troll;
	t_struct		*s_list;

	i = 0;
	dp = opendir(str);
	if (!(s_list = malloc(sizeof(t_struct) * nbrfile)))
		exit(0);
	while ((lol = readdir(dp)) != NULL)
		if ((name = ft_strdup(lol->d_name)) && name[0] != '.')
		{
			s_list[i].name = name;
			troll = ft_strjoin(str, "/");
			path = ft_strjoin(troll, name);
			our_stat(path, s_list, i++);
			free(troll);
			free(path);
		}
		else
			free(name);
	closedir(dp);
	return (s_list);
}

t_struct	*list_all(char *str, int nbrfile, DIR *dp, char *name)
{
	struct dirent	*lol;
	int				i;
	char			*path;
	char			*troll;
	t_struct		*s_list;

	i = 0;
	dp = opendir(str);
	if (!(s_list = malloc(sizeof(t_struct) * nbrfile)))
		exit(0);
	while ((lol = readdir(dp)) != NULL)
	{
		name = ft_strdup(lol->d_name);
		s_list[i].name = name;
		troll = ft_strjoin(str, "/");
		path = ft_strjoin(troll, name);
		our_stat(path, s_list, i);
		free(troll);
		free(path);
		i++;
	}
	closedir(dp);
	return (s_list);
}
