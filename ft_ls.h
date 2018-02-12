/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:00:26 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/09 18:36:57 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/xattr.h>

typedef struct	s_variable
{
	int			d;
	int			f;
	int			o;
	int			stock;
	DIR			*dp;
	struct stat	s_filestat;
}				t_variables;

typedef struct	s_check
{
	char		**fileerror;
	char		**file;
	char		**directory;
	int			taille_fileerror;
	int			taille_file;
	int			taille_directory;
}				t_check;

typedef struct	s_max
{
	size_t		nbmaxliens;
	size_t		nbmaxsize;
	size_t		nbmaxgroupe;
	size_t		nbmaxproprio;
	size_t		nbmaxminor;
	size_t		nbmaxmajor;
}				t_max;

typedef struct	s_flag
{
	int rmaj;
	int a;
	int r;
	int t;
	int l;
	int gmaj;
	int g;
}				t_flag;

typedef struct	s_struct
{
	char		*name;
	char		*mode;
	int			nbrlien;
	char		*proprio;
	char		*groupe;
	int			taille;
	char		*modif;
	int			time;
	int			itoapro;
	int			itoagrp;
	int			blocks;
	char		*namesymb;
	int			major;
	int			minor;
}				t_struct;

void			initialisation(t_struct *s_list, int i);

void			printstruct(t_struct *s_list_name, int taille,
				t_flag *flag, int d);
t_struct		*trie_ascii(t_struct *s_list_name, int taille);
void			trie_ascii_inverse(t_struct *s_list_name, int taille);
t_struct		*list(char *str, int nbrfile, DIR *dp, char *name);
t_struct		*list_all(char *str, int nbrfile, DIR *dp, char *name);
void			ft_ls(DIR *dp, char *str, t_flag *flag, int nbrfile);
void			ft_ls_rmaj(char *namedirectory, t_flag *flag,
				int i, int nbrfile);
void			ft_ls_all(DIR *dp, char *str, t_flag *flag);
void			ft_ls_rmaj_all(char *namedirectory, t_flag *flag,
				int i, int nbrfile);
char			*modif_time(char *str, char *real);
void			ft_rmaj(char *str, t_flag *flag);
void			list_all_directory(char *str, t_struct *s_list);
void			list_directory(char *str, t_struct *s_list);
void			our_stat(char *str, t_struct *s_list, int i);
void			trie_date_inverse(t_struct *s_list, int taille);
void			trie_date(t_struct *s_list, int taille);
void			f_flag(char **argv, t_flag *flag, int i);
t_check			checkerror(int i, char **argv, int argc);
void			trie_ascii_char(char **str, int taille);
void			trie_ascii_char_inverse(char **str, int taille);
void			date_char(char **str, int taille);
void			date_char_inverse(char **str, int taille);

void			grppro(t_struct *s_list, int i, struct stat s_filestat);
char			*lmode2(char *mode, char *str);
void			our_stat2(t_struct *s_list, int i, char *str);
void			modif_time2(char *tmp, char *real);
void			modif_time3(char *tmp, char *real);

t_max			padding(t_struct *s_list, int taille, t_max *s_max);

void			flaginit(t_flag *flag);
void			flagerror(char **argv, int i);

void			checkfileerror(t_check check);
void			checkfile(t_check check, t_flag flag, int i);
void			checkdirecterror(t_check check, t_flag flag);
void			checkdirectory(t_check check, t_flag flag, int i);

void			checkdirectory2(t_check check, t_flag flag);
void			checkdirecterror2(t_flag flag, t_check *check);
void			printerrordirect(int i, t_check check);
void			checkfile2(t_struct *s_file, t_check check,
				int i, t_flag *flag);

void			checkerror1(int i, char **argv, int argc, t_variables *vari);
void			checkerror2(int i, char **argv, int argc, t_check *check);

size_t			maxliens(t_struct *s_list, int taille);
size_t			maxsize(t_struct *s_list, int taille);
size_t			maxgroupe(t_struct *s_list, int taille);
size_t			maxproprio(t_struct *s_list, int taille);
size_t			maxminor(t_struct *s_list, int taille);
size_t			maxmajor(t_struct *s_list, int taille);
int				total_l(t_struct *s_list, int taille);

t_struct		*triemajr(t_flag *flag, t_struct *s_list, int nbrfile);
void			printerr(t_struct *s_list, char *name, int i, char *troll);
void			printname(char *name, char *troll, DIR *dp, t_flag *flag);
int				comptfile(DIR *dp, int nbrfile);
void			test(t_struct *s_list, int i, char *namedirectory,
				t_flag *flag);

void			print1(t_struct *s_list, int i, t_max *s_max);
int				print2(t_struct *s_list, int i, int stock, t_max *s_max);
void			print3(t_struct *s_list, int i, int stock, t_max *s_max);
void			print4(t_struct *s_list, int i);
void			print5(t_struct *s_list, int i, t_flag *flag, int d);
void			print6(t_struct *s_list, int i, t_max *s_max);
void			print7(t_struct *s_list, int taille, int d, t_flag *flag);
void			print8(t_struct *s_list, int i, t_max *s_max);
#endif
