# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:52:14 by myoung            #+#    #+#              #
#    Updated: 2019/07/05 19:46:36 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
INC = -I ./include

MAIN = main.c

FILES = ft_putchar.c ft_putstr.c ft_strlen.c ft_bzero.c ft_atoi.c ft_strdup.c\
ft_param.c print_oO.c reshetka_o.c ft_printf_xX.c reshetka.c printf_itoabase.c\
len_base.c ft_printfs.c ft_print_C.c ft_parammode.c ft_print_d.c ft_printf.c ft_itoaunion.c\
pow_nb.c slozhenie.c mantisa_str.c otric_poryadok.c rec_mas.c double_znak.c ft_count_mantisa.c\
count_poryadok.c ft_bzero.c delenie.c vozvedenie.c ymnozhenie.c ft_printf_f.c ft_printfper.c

OBJ = $(addprefix build/, $(FILES:.c=.o))
SRC = $(addprefix src/, $(FILES))

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) crs $@ $^
	echo "Creating $(NAME)"

build/%.o: src/%.c | build
	@echo "Doing things to $@"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
build/%.o: src/utils/%.c | build
	@echo "Doing things to $@"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
build/%.o: src/float/%.c | build
	@echo "Doing things to $@"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
	mkdir build

clean:
	@rm -rf build
	@echo "clean successful"

fclean: clean
	@echo "Removing $(NAME)"
	rm -f $(NAME)

test:
	make re
	$(CC) $(MAIN) $(NAME)  $(INC)
	./a.out

re: fclean all
