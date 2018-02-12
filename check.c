/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:59:23 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 10:38:09 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	checkfileerror(t_check check)
{
	int				i;
	struct stat		s_error;

	i = 0;
	if (check.taille_fileerror)
	{
		while (i < check.taille_fileerror)
		{
			trie_ascii_char(check.fileerror, check.taille_fileerror);
			lstat(check.fileerror[i], &s_error);
			ft_putstr_fd("ls: ", 1);
			ft_putstr_fd(check.fileerror[i], 1);
			ft_putstr_fd(": ", 1);
			perror("");
			i++;
		}
	}
}

void	checkfile(t_check check, t_flag flag, int i)
{
	t_struct *s_file;

	i = 0;
	if (check.taille_file)
	{
		if (flag.t && !flag.r)
			date_char(check.file, check.taille_file);
		else if (flag.t && flag.r)
			date_char_inverse(check.file, check.taille_file);
		else if (flag.r)
			trie_ascii_char_inverse(check.file, check.taille_file);
		else
			trie_ascii_char(check.file, check.taille_file);
		while (i < check.taille_file)
			i++;
		s_file = malloc(sizeof(t_struct) * i);
		i = -1;
		while (++i < check.taille_file)
		{
			our_stat(check.file[i], s_file, i);
			s_file[i].name = check.file[i];
		}
		checkfile2(s_file, check, i, &flag);
		free(s_file);
	}
}

void	printerror(char *str)
{
	ft_putstr_fd("ls: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putchar_fd('\n', 1);
}

void	doit(t_flag flag, int i, DIR *dp, char *str)
{
	if (flag.rmaj)
	{
		closedir(dp);
		ft_rmaj(str, &flag);
	}
	else if (flag.a)
		ft_ls_all(dp, str, &flag);
	else
		ft_ls(dp, str, &flag, i);
}

void	checkdirectory(t_check check, t_flag flag, int i)
{
	DIR			*dp;

	if (check.taille_directory)
	{
		checkdirectory2(check, flag);
		while (i < check.taille_directory)
		{
			if (check.taille_directory > 1 || check.taille_file ||
					check.taille_fileerror)
			{
				ft_putstr(check.directory[i]);
				ft_putstr(":\n");
			}
			if ((dp = opendir(check.directory[i])) == NULL)
				printerror(check.directory[i]);
			else
				doit(flag, i, dp, check.directory[i]);
			if (++i < check.taille_directory)
				ft_putchar('\n');
		}
	}
}
