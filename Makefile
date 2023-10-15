# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:26:20 by abelahce          #+#    #+#              #
#    Updated: 2022/08/07 01:36:07 by abelahce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: philo

CC=gcc

HEADER=philo.h

UTILS=utils.o

CFLAGS=-Wall -Wextra -Werror -g -pthread 

NAME=philo

SRC := main.c \
		utils.c	\
		ft_strlen.c	\
		parsing.c	\
		ft_atoi.c	\
		ft_isdigit.c	\
		spread.c \
		shinigami.c \
		philosophers.c \
		# philo.c	\

OBJ := $(SRC:.c=.o)

HDR := philo.h

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf philo

re: fclean all