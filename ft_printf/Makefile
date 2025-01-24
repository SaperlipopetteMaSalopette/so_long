# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 23:19:50 by thofstet          #+#    #+#              #
#    Updated: 2025/01/25 00:05:03 by thofstet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC =	ft_numlen ft_print_char ft_print_hexa ft_print_int ft_print_string ft_print_unsigned_dec ft_printf ft_putnbr ft_putstr ft_strchr_2 ft_strlen_2 ft_print_pointer
SRCS =	$(addsuffix .c, $(SRC))

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SILENT:
