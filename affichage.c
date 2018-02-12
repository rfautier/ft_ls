/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:38:17 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 11:01:50 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	maxmajor(t_struct *s_list, int taille)
{
	int		i;
	size_t	max;
	char	*tmp;

	max = 0;
	i = 0;
	while (i < taille)
	{
		tmp = ft_itoa(s_list[i].major);
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

void	print6(t_struct *s_list, int i, t_max *s_max)
{
	int o;

	o = 0;
	ft_putstr(s_list[i].groupe);
	while ((o + ft_strlen(s_list[i].groupe)) != s_max->nbmaxgroupe)
	{
		ft_putchar(' ');
		o++;
	}
	if (s_list[i].itoagrp)
		free(s_list[i].groupe);
	o = 0;
	ft_putstr("  ");
}

void	printterminal(t_struct *s_list, int i)
{
	ft_putchar(' ');
	ft_putstr(s_list[i].modif);
	ft_putchar(' ');
}

void	printftout(t_struct *s_list, int taille, t_flag *flag, int d)
{
	int		i;
	int		stock;
	t_max	s_max;

	stock = 0;
	i = -1;
	s_max = padding(s_list, taille, &s_max);
	print7(s_list, taille, d, flag);
	while (++i < taille)
	{
		print1(s_list, i, &s_max);
		if (!flag->g)
			print8(s_list, i, &s_max);
		print6(s_list, i, &s_max);
		if (s_list[i].mode[0] == 'c' || s_list[i].mode[0] == 'b')
			print2(s_list, i, stock = 6, &s_max);
		else
			print3(s_list, i, stock, &s_max);
		printterminal(s_list, i);
		if (flag->gmaj)
			print4(s_list, i);
		else
			ft_putstr(s_list[i].name);
		print5(s_list, i, flag, d);
	}
}

void	printstruct(t_struct *s_list, int taille, t_flag *flag, int d)
{
	int i;

	i = -1;
	if (flag->l || flag->g)
		printftout(s_list, taille, flag, d);
	else
	{
		while (++i < taille)
		{
			if (flag->gmaj)
				print4(s_list, i);
			else
				ft_putstr(s_list[i].name);
			ft_putchar('\n');
			if (s_list[i].mode[0] == 'l')
				free(s_list[i].namesymb);
			if (!flag->rmaj && s_list[i].nbrlien)
			{
				if (d != 3)
					free(s_list[i].name);
				free(s_list[i].mode);
				free(s_list[i].modif);
			}
		}
	}
}
