/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roption.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:50:27 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 12:56:23 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_struct	*triemajr(t_flag *flag, t_struct *s_list, int nbrfile)
{
	if (flag->r && !flag->t)
		trie_ascii_inverse(s_list, nbrfile);
	else if (flag->t && !flag->r)
		trie_date(s_list, nbrfile);
	else if (flag->t && flag->r)
		trie_date_inverse(s_list, nbrfile);
	else
		s_list = trie_ascii(s_list, nbrfile);
	printstruct(s_list, nbrfile, flag, 0);
	return (s_list);
}

void		printerr(t_struct *s_list, char *name, int i, char *troll)
{
	ft_putchar('\n');
	ft_putstr(name);
	ft_putstr(":\n");
	ft_putstr_fd("ls: ", 1);
	ft_putstr_fd(s_list[i].name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putchar_fd('\n', 1);
	free(name);
	free(troll);
}

void		printname(char *name, char *troll, DIR *dp, t_flag *flag)
{
	closedir(dp);
	ft_putchar('\n');
	ft_putstr(name);
	ft_putstr(":\n");
	if (!flag->a)
		ft_ls_rmaj(name, flag, -1, 0);
	else
		ft_ls_rmaj_all(name, flag, -1, 0);
	free(name);
	free(troll);
}

int			comptfile(DIR *dp, int nbrfile)
{
	struct dirent	*lol;
	char			*name;

	while ((lol = readdir(dp)) != NULL)
	{
		name = lol->d_name;
		if (name[0] != '.')
			nbrfile++;
	}
	return (nbrfile);
}

void		test(t_struct *s_list, int i, char *namedirectory, t_flag *flag)
{
	char	*troll;
	char	*name;
	DIR		*dp;

	if (!(ft_strcmp(namedirectory, "/")))
		namedirectory = "";
	troll = ft_strjoin(namedirectory, "/");
	name = ft_strjoin(troll, s_list[i].name);
	if ((dp = opendir(name)) == NULL)
		printerr(s_list, name, i, troll);
	else
	{
		if (s_list[i].mode[3] == 'x' && s_list[i].mode[6] == 'x' &&
				s_list[i].mode[9] == 'x' && ft_strcmp(s_list[i].name, "Hack"))
			printname(name, troll, dp, flag);
		else
		{
			closedir(dp);
			printerr(s_list, name, i, troll);
		}
	}
}
