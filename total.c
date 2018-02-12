/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 19:51:18 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/08 11:16:59 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		total_l(t_struct *s_list, int taille)
{
	int i;
	int total;

	total = 0;
	i = 0;
	while (i < taille)
	{
		total = total + s_list[i].blocks;
		i++;
	}
	return (total);
}
