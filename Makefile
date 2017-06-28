# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/03 19:55:55 by tpan              #+#    #+#              #
#    Updated: 2017/06/27 17:02:52 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lem-in
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -g
LEAKCHECK = -g
SRCFILES = 	parse.c error.c parse_main_functions.c parse_storage_functions.c \
			lem_in.c solve.c print_ants.c connections.c init.c parse_helpers.c\

SRC = $(addprefix $(SRCDIR),$(SRCFILES))
OBJ = $(addprefix $(OBJDIR),$(SRCFILES:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBFTDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./includes/

.PHONY:$(NAME), all, clean, fclean, re



all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(INCDIR)*.h $(OBJ)
	echo "Compiling Lem_in"
	$(CC) $(CFLAGS) -g -c -I$(INCDIR) $(SRC)
	mv *.o $(OBJDIR)
	$(CC) $(CFLAGS) -g -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	echo "Lem_in: Compiled"

$(LIBFT):
	make -C $(LIBFTDIR) all

$(FT_PRINTF): $(LIBFT)
	make -C $(FTPFDIR) all

clean:
	echo "Cleaning push_swap"
	rm -rf $(OBJDIR)
	rm -rf lem_in_debug
	rm -rf lem_in_debug.dSYM
	rm -rf lem_in_leakcheck
	rm -rf lem_in_leakcheck.dSYM
	make -C $(LIBFTDIR) clean
	make -C $(FTPFDIR) clean

fclean: clean
	echo "FCleaning lem_in"
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	echo "Compiling lem_in with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS) -o $(NAME)
	echo "Compiled lem_in debug"

leakcheck: $(LIBFT) $(FT_PRINTF)
	echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK) -o lem_in_leakcheck
	echo "Compiled lem_in with leakchecker"
