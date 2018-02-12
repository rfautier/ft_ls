/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 19:47:56 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 18:44:32 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print1(t_struct *s_list, int i, t_max *s_max)
{
	char	*tmp;
	int		o;

	o = 0;
	ft_putstr(s_list[i].mode);
	ft_putstr("  ");
	tmp = ft_itoa(s_list[i].nbrlien);
	while (o + ft_strlen(tmp) != s_max->nbmaxliens)
	{
		ft_putchar(' ');
		o++;
	}
	free(tmp);
	o = 0;
	ft_putnbr(s_list[i].nbrlien);
	ft_putchar(' ');
}

void	print8(t_struct *s_list, int i, t_max *s_max)
{
	int o;

	o = 0;
	ft_putstr(s_list[i].proprio);
	while ((o + ft_strlen(s_list[i].proprio)) != s_max->nbmaxproprio)
	{
		ft_putchar(' ');
		o++;
	}
	if (s_list[i].itoapro)
		free(s_list[i].proprio);
	ft_putstr("  ");
}

int		print2(t_struct *s_list, int i, int stock, t_max *s_max)
{
	char	*tmp;
	int		o;

	o = 0;
	tmp = ft_itoa(s_list[i].major);
	while ((o + ft_strlen(tmp)) != s_max->nbmaxmajor)
	{
		ft_putchar(' ');
		o++;
	}
	free(tmp);
	o = 0;
	ft_putnbr(s_list[i].major);
	ft_putstr(", ");
	tmp = ft_itoa(s_list[i].minor);
	while ((o + ft_strlen(tmp)) != s_max->nbmaxminor)
	{
		ft_putchar(' ');
		o++;
	}
	free(tmp);
	o = 0;
	ft_putnbr(s_list[i].minor);
	return (stock);
}

void	print4(t_struct *s_list, int i)
{
	if (s_list[i].mode[0] == 'd')
	{
		ft_putstr("\033[34;1m");
		ft_putstr(s_list[i].name);
		ft_putstr("\033[0m");
	}
	else if (s_list[i].mode[0] == 'l')
	{
		ft_putstr("\033[33;1m");
		ft_putstr(s_list[i].name);
		ft_putstr("\033[0m");
	}
	else if (s_list[i].mode[0] == 'c')
	{
		ft_putstr("\033[32;1m");
		ft_putstr(s_list[i].name);
		ft_putstr("\033[0m");
	}
	else
	{
		ft_putstr("\033[37;1m");
		ft_putstr(s_list[i].name);
		ft_putstr("\033[0m");
	}
}

void	print5(t_struct *s_list, int i, t_flag *flag, int d)
{
	if (s_list[i].mode[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(s_list[i].namesymb);
		free(s_list[i].namesymb);
	}
	ft_putchar('\n');
	if (!flag->rmaj && d != 3 && s_list[i].nbrlien)
	{
		free(s_list[i].name);
		free(s_list[i].mode);
		free(s_list[i].modif);
	}
	if (d == 3 && s_list[i].nbrlien)
	{
		free(s_list[i].mode);
		free(s_list[i].modif);
	}
}
