/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 18:40:40 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/08 11:00:47 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	maxliens(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;
	char	*tmp;

	max = 0;
	i = 0;
	while (i < taille)
	{
		tmp = ft_itoa(s_list[i].nbrlien);
		if (ft_strlen(tmp) > max)
		{
			max = ft_strlen(tmp);
			free(tmp);
		}
		else
			free(tmp);
		i++;
	}
	return (max);
}

size_t	maxsize(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;
	char	*tmp;

	max = 0;
	i = 0;
	while (i < taille)
	{
		tmp = ft_itoa(s_list[i].taille);
		if (ft_strlen(tmp) > max)
		{
			max = ft_strlen(tmp);
			free(tmp);
		}
		else
			free(tmp);
		i++;
	}
	return (max);
}

size_t	maxgroupe(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;

	max = 0;
	i = 0;
	while (i < taille)
	{
		if (ft_strlen(s_list[i].groupe) > max)
			max = ft_strlen(s_list[i].groupe);
		i++;
	}
	return (max);
}

size_t	maxproprio(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;

	max = 0;
	i = 0;
	while (i < taille)
	{
		if (ft_strlen(s_list[i].proprio) > max)
			max = ft_strlen(s_list[i].proprio);
		i++;
	}
	return (max);
}

size_t	maxminor(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;
	char	*tmp;

	max = 0;
	i = 0;
	while (i < taille)
	{
		tmp = ft_itoa(s_list[i].minor);
		if (ft_strlen(tmp) > max)
		{
			max = ft_strlen(tmp);
			free(tmp);
		}
		else
			free(tmp);
		i++;
	}
	return (max);
}
