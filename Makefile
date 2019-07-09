# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myoung <myoung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:52:14 by myoung            #+#    #+#              #
#    Updated: 2019/07/09 14:45:30 by blomo            ###   ########.fr        #
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
slozhenieminusdrob.c minusdroppart.c slosheniedrob.c drobpart.c realpart.c pow_nb.c ft_printf_f.c\
slozhenie.c otric_poryadok.c rec_mas.c double_znak.c count_poryadok.c delenie.c\
vozvedenie.c ymnozhenie.c precisiondouble.c parsingfloat.c ft_strcpy.c ft_printfper.c ft_printf_p.c

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
	@rm -rf *.o build
	@echo "clean successful"

fclean: clean
	@echo "Removing $(NAME)"
	rm -f *.a $(NAME)

test:
	make re
	$(CC) $(MAIN) $(NAME)  $(INC)
	./a.out

re: fclean all
