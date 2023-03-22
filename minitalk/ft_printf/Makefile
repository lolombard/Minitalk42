# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:   mgala <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:22:43 by   mgala           #+#    #+#              #
#    Updated: 2022/11/08 16:53:41 by   mgala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRC :=	ft_numbers.c \
	ft_printf.c \
	ft_words.c \
	

OBJS = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o:%.c
	$(CC) -c $(CFLAG) -I. $< -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
