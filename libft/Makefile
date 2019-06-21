# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpersin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 14:12:29 by lpersin           #+#    #+#              #
#    Updated: 2019/06/21 18:33:35 by lpersin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:%.c=%.o)
NAME = libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar $(ARFLAGS) $@ $^

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY:re
re: fclean all
