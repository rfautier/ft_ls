/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:16:08 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 14:16:04 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	checkerror1(int i, char **argv, int argc, t_variables *vari)
{
	while (i < argc)
	{
		if (lstat(argv[i], &vari->s_filestat) == -1)
			vari->o++;
		else if (S_ISDIR(vari->s_filestat.st_mode))
			vari->d++;
		else
			vari->f++;
		i++;
	}
}

void	checkerror2(int i, char **argv, int argc, t_check *check)
{
	t_variables vari;

	vari.d = 0;
	vari.f = 0;
	vari.o = 0;
	while (i < argc)
	{
		if ((lstat(argv[i], &vari.s_filestat)) == -1)
			check->fileerror[vari.o++] = argv[i];
		else if (S_ISDIR(vari.s_filestat.st_mode))
			check->directory[vari.d++] = argv[i];
		else
			check->file[vari.f++] = argv[i];
		i++;
	}
}

t_check	checkerror(int i, char **argv, int argc)
{
	t_check		check;
	t_variables vari;

	vari.d = 0;
	vari.f = 0;
	vari.o = 0;
	checkerror1(i, argv, argc, &vari);
	check.fileerror = malloc(sizeof(char *) * (vari.o));
	check.directory = malloc(sizeof(char *) * (vari.d));
	check.file = malloc(sizeof(char *) * (vari.f));
	checkerror2(i, argv, argc, &check);
	check.taille_fileerror = vari.o;
	check.taille_file = vari.f;
	check.taille_directory = vari.d;
	return (check);
}
