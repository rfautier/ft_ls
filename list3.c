/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:46:56 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/11 11:35:15 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initialisation(t_struct *s_list, int i)
{
	char *tmp;

	tmp = malloc(sizeof(char) * 11);
	tmp = "----------";
	s_list[i].proprio = " ";
	s_list[i].groupe = " ";
	s_list[i].mode = tmp;
	s_list[i].modif = "          ";
	s_list[i].nbrlien = 0;
	s_list[i].blocks = 0;
	s_list[i].time = 0;
}
