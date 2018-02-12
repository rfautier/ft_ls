/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionR.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:52:39 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 11:03:42 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_rmaj(char *namedirectory, t_flag *flag, int i, int nbrfile)
{
	char		*name;
	DIR			*dp;
	t_struct	*s_list;

	if (!(dp = opendir(namedirectory)))
		return ;
	nbrfile = comptfile(dp, nbrfile);
	closedir(dp);
	if (!(name = NULL) && nbrfile == 0)
		return ;
	s_list = list(namedirectory, nbrfile, dp, name);
	s_list = triemajr(flag, s_list, nbrfile);
	while (++i < nbrfile)
	{
		if (s_list[i].mode[0] == 'd')
			test(s_list, i, namedirectory, flag);
		free(s_list[i].mode);
		free(s_list[i].name);
		free(s_list[i].modif);
	}
	free(s_list);
	return ;
}

void	ft_ls_rmaj_all(char *namedirectory, t_flag *flag, int i, int nbrfile)
{
	struct dirent	*lol;
	char			*name;
	DIR				*dp;
	t_struct		*s_list;

	if (!(dp = opendir(namedirectory)))
		return ;
	while ((lol = readdir(dp)) != NULL)
		nbrfile++;
	closedir(dp);
	if (!(name = NULL) && nbrfile == 0)
		return ;
	s_list = list_all(namedirectory, nbrfile, dp, name);
	s_list = triemajr(flag, s_list, nbrfile);
	while (++i < nbrfile)
	{
		if (s_list[i].mode[0] == 'd' && (ft_strcmp(s_list[i].name, ".")
					!= 0 && ft_strcmp(s_list[i].name, "..")))
			test(s_list, i, namedirectory, flag);
		free(s_list[i].mode);
		free(s_list[i].modif);
		free(s_list[i].name);
	}
	free(s_list);
	return ;
}

void	ft_rmaj(char *str, t_flag *flag)
{
	char	*namedirectory;
	int		i;
	int		nbrfile;

	nbrfile = 0;
	i = -1;
	namedirectory = str;
	if (flag->a)
		ft_ls_rmaj_all(namedirectory, flag, i, nbrfile);
	else
		ft_ls_rmaj(namedirectory, flag, i, nbrfile);
}
