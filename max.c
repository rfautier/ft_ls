/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:35:15 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/08 10:59:50 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_max	padding(t_struct *s_list, int taille, t_max *s_max)
{
	s_max->nbmaxmajor = maxmajor(s_list, taille);
	s_max->nbmaxminor = maxminor(s_list, taille);
	s_max->nbmaxsize = maxsize(s_list, taille);
	s_max->nbmaxgroupe = maxgroupe(s_list, taille);
	s_max->nbmaxproprio = maxproprio(s_list, taille);
	s_max->nbmaxliens = maxliens(s_list, taille);
	return (*s_max);
}
