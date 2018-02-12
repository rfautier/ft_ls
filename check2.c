/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:44:40 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 13:39:25 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	checkdirectory2(t_check check, t_flag flag)
{
	if (flag.t && !flag.r)
		date_char(check.directory, check.taille_directory);
	else if (flag.t && flag.r)
		date_char_inverse(check.directory, check.taille_directory);
	else if (flag.r)
		trie_ascii_char_inverse(check.directory, check.taille_directory);
	else
		trie_ascii_char(check.directory, check.taille_directory);
}

void	checkfile2(t_struct *s_file, t_check check, int i, t_flag *flag)
{
	printstruct(s_file, i, flag, 3);
	if (check.taille_directory)
		ft_putchar('\n');
}
