/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:44:18 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 13:06:43 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		trie_ascii_char_inverse(char **str, int taille)
{
	char	*tmp;
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (i < taille - 1)
	{
		while ((str[i][o] == str[i + 1][o]) &&
				(str[i][o] != '\0' && str[i + 1][o] != '\0'))
			o++;
		if (str[i][o] < str[i + 1][o])
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = -1;
		}
		o = 0;
		i++;
	}
}

void		trie_ascii_char(char **str, int taille)
{
	char	*tmp;
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (i < taille - 1)
	{
		while ((str[i][o] == str[i + 1][o]) &&
				(str[i][o] != '\0' && str[i + 1][o] != '\0'))
			o++;
		if (str[i][o] > str[i + 1][o])
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = -1;
		}
		o = 0;
		i++;
	}
}

void		deplacement(t_struct s_list, t_struct *s_list_trie, int o, int maxo)
{
	int r;

	r = 0;
	o = maxo + 1;
	while (!(ft_strcmp(s_list.name, s_list_trie[--o].name) >= 0))
	{
		s_list_trie[o + 1] = s_list_trie[o];
		if (o == 0 && (r = 1))
			break ;
	}
	if (r == 1)
		s_list_trie[o] = s_list;
	else
		s_list_trie[++o] = s_list;
}

t_struct	*trie_ascii(t_struct *s_list, int taille)
{
	int			i;
	int			o;
	int			maxo;
	t_struct	*s_list_trie;

	i = 0;
	o = 1;
	maxo = 0;
	if (!(s_list_trie = malloc(sizeof(t_struct) * taille)))
		exit(0);
	s_list_trie[0] = s_list[0];
	while (++i != taille)
	{
		if (ft_strcmp(s_list[i].name, s_list_trie[maxo].name) >= 0)
			s_list_trie[maxo + 1] = s_list[i];
		else
			deplacement(s_list[i], s_list_trie, o, maxo);
		maxo = maxo + 1;
	}
	free(s_list);
	s_list = s_list_trie;
	return (s_list);
}

void		trie_ascii_inverse(t_struct *s_list_name, int taille)
{
	t_struct	tmp;
	int			i;
	int			o;

	i = 0;
	o = 0;
	while (i != taille - 1)
	{
		while ((s_list_name[i].name[o] == s_list_name[i + 1].name[o]) &&
				(s_list_name[i].name[o] != '\0' &&
				s_list_name[i + 1].name[o] != '\0'))
			o++;
		if (s_list_name[i].name[o] < s_list_name[i + 1].name[o])
		{
			tmp = s_list_name[i + 1];
			s_list_name[i + 1] = s_list_name[i];
			s_list_name[i] = tmp;
			i = -1;
			o = 0;
		}
		o = 0;
		i++;
	}
}
