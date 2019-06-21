# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpersin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 18:33:14 by lpersin           #+#    #+#              #
#    Updated: 2019/06/21 18:33:21 by lpersin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft
LDFLAGS = -L./libft -lft

SRCDIR = src
OBJDIR = obj
#BINDIR = bin
LIBDIR = libft

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = ft_ls

LIB = libft.a

all: $(NAME) 

$(NAME): $(OBJECTS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB) :
	$(MAKE) -C $(LIBDIR)

.PHONY: clean fclean re

clean:
	$(MAKE) clean -C  $(LIBDIR)
	/bin/rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C  $(LIBDIR)
	/bin/rm -rf $(NAME)

re: fclean all
