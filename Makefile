#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:54:38 by rfautier          #+#    #+#              #
#    Updated: 2018/01/11 13:31:56 by rfautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_NAME =	main.c\
			list.c\
			trie.c\
			affichage.c\
			trie_date.c\
			checkerror.c\
			maxfile.c\
			print.c\
			print2.c\
			total.c\
			check.c\
			flag.c\
			check2.c\
			list2.c\
			list3.c\
			roption.c\
			optionr.c\
			max.c

SRC_PATH = .
OBJ_PATH = .
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -I./libft/
LDFLAGS = -Llibft/
LDLIBS = -lft
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: library $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

library:
	make -C ./libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

.PHONY: all, clean, fclean, re, library

clean:
		/bin/rm -f $(OBJ)
		make clean -C ./libft
fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C ./libft

re: fclean all
