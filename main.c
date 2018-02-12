/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:45:39 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 18:25:34 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	othermain(char **argv, int argc)
{
	int		i;
	t_flag	flag;
	t_check	check;

	i = 0;
	flaginit(&flag);
	f_flag(argv, &flag, i);
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
		i++;
	if (argv[i] == NULL)
	{
		argv[i] = ".";
		argc++;
	}
	check = checkerror(i, argv, argc);
	checkfileerror(check);
	checkfile(check, flag, i);
	checkdirectory(check, flag, 0);
	free(check.file);
	free(check.fileerror);
	free(check.directory);
}

void	ft_ls_all(DIR *dp, char *str, t_flag *flag)
{
	int				nbrfile;
	struct dirent	*lol;
	t_struct		*s_list;
	char			*name;

	name = NULL;
	nbrfile = 0;
	while ((lol = readdir(dp)) != NULL)
		nbrfile++;
	closedir(dp);
	s_list = list_all(str, nbrfile, dp, name);
	if (flag->r)
		trie_ascii_inverse(s_list, nbrfile);
	if (flag->t && flag->r)
		trie_date_inverse(s_list, nbrfile);
	else if (flag->t && !flag->r)
		trie_date(s_list, nbrfile);
	else if (!flag->r && !flag->t)
		s_list = trie_ascii(s_list, nbrfile);
	printstruct(s_list, nbrfile, flag, 1);
	free(s_list);
}

void	ft_ls(DIR *dp, char *str, t_flag *flag, int nbrfile)
{
	struct dirent	*lol;
	char			*name;
	t_struct		*s_list;

	nbrfile = 0;
	while ((lol = readdir(dp)) != NULL)
	{
		name = lol->d_name;
		if (name[0] != '.')
			nbrfile++;
	}
	closedir(dp);
	s_list = list(str, nbrfile, dp, name);
	if (nbrfile == 0)
		return ;
	if (flag->r)
		trie_ascii_inverse(s_list, nbrfile);
	if (flag->t && flag->r)
		trie_date_inverse(s_list, nbrfile);
	else if (flag->t && !flag->r)
		trie_date(s_list, nbrfile);
	else if (!flag->r && !flag->t)
		s_list = trie_ascii(s_list, nbrfile);
	printstruct(s_list, nbrfile, flag, 1);
	free(s_list);
}

int		main(int argc, char **argv)
{
	if (argv[1] == NULL)
	{
		argv[1] = ".";
		argc++;
	}
	if (argv[1][0] == '-' && argv[1][1])
	{
		if (argv[2] == NULL)
		{
			argv[2] = ".";
			argc++;
		}
	}
	othermain(argv, argc);
}
