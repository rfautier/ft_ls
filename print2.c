/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:20:26 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 18:43:44 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print7(t_struct *s_list, int taille, int d, t_flag *flag)
{
	if (d == 1 || flag->rmaj)
	{
		ft_putstr("total ");
		ft_putnbr(total_l(s_list, taille));
		ft_putchar('\n');
	}
}

void	print3(t_struct *s_list, int i, int stock, t_max *s_max)
{
	char	*tmp;
	int		o;

	o = 0;
	tmp = ft_itoa(s_list[i].taille);
	while (((o - stock) + ft_strlen(tmp)) != s_max->nbmaxsize)
	{
		ft_putchar(' ');
		o++;
	}
	o = 0;
	ft_putnbr(s_list[i].taille);
	free(tmp);
}
