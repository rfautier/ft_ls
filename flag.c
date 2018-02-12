/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:50:03 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/08 12:00:17 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	f_flag(char **argv, t_flag *flag, int i)
{
	int o;

	o = 0;
	while (argv[++i] != NULL && argv[i][0] == '-' && argv[i][1])
	{
		flagerror(argv, i);
		while (argv[i][o++])
		{
			if (argv[i][o] == 'R')
				flag->rmaj = 1;
			if (argv[i][o] == 'r')
				flag->r = 1;
			if (argv[i][o] == 'a')
				flag->a = 1;
			if (argv[i][o] == 't')
				flag->t = 1;
			if (argv[i][o] == 'l')
				flag->l = 1;
			if (argv[i][o] == 'G')
				flag->gmaj = 1;
			if (argv[i][o] == 'g')
				flag->g = 1;
		}
		o = 0;
	}
}

void	flaginit(t_flag *flag)
{
	flag->rmaj = 0;
	flag->r = 0;
	flag->a = 0;
	flag->t = 0;
	flag->gmaj = 0;
	flag->l = 0;
	flag->g = 0;
}

void	flagerror(char **argv, int i)
{
	int o;

	o = 1;
	while (argv[i][o])
	{
		if (argv[i][o] != 'R' && argv[i][o] != 'r' && argv[i][o] != 'a'
				&& argv[i][o] != 't' && argv[i][o] != 'l' &&
				argv[i][o] != 'G' && argv[i][o] != 'g')
		{
			ft_putstr_fd("ls: illegal option -- ", 1);
			ft_putchar_fd(argv[i][o], 1);
			ft_putstr_fd("\nusage: ls [-RratlGg] [file ...]\n", 1);
			exit(0);
		}
		o++;
	}
}
