/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:36:16 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/08 12:10:02 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	date_char_inverse(char **str, int taille)
{
	char		*tmp;
	int			i;
	struct stat s_filestat1;
	struct stat s_filestat2;

	i = 0;
	while (i != taille - 1)
	{
		lstat(str[i], &s_filestat1);
		lstat(str[i + 1], &s_filestat2);
		if (s_filestat1.st_mtime > s_filestat2.st_mtime)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	date_char(char **str, int taille)
{
	char		*tmp;
	int			i;
	struct stat s_filestat1;
	struct stat s_filestat2;

	i = 0;
	while (i != taille - 1)
	{
		lstat(str[i], &s_filestat1);
		lstat(str[i + 1], &s_filestat2);
		if (s_filestat1.st_mtime < s_filestat2.st_mtime)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	trie_date(t_struct *s_list, int taille)
{
	t_struct	tmp;
	int			i;

	i = 0;
	while (i != taille - 1)
	{
		if (s_list[i].time < s_list[i + 1].time)
		{
			tmp = s_list[i + 1];
			s_list[i + 1] = s_list[i];
			s_list[i] = tmp;
			i = -1;
		}
		i++;
	}
}

void	trie_date_inverse(t_struct *s_list, int taille)
{
	t_struct	tmp;
	int			i;

	i = 0;
	while (i != taille - 1)
	{
		if (s_list[i].time > s_list[i + 1].time)
		{
			tmp = s_list[i + 1];
			s_list[i + 1] = s_list[i];
			s_list[i] = tmp;
			i = -1;
		}
		i++;
	}
}
