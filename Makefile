CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -g
LDFLAGS = -L./libft -lft

SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = libft

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
EXEC = ft_ls

LIB = libft.a

all: $(LIBDIR)/$(LIB) $(BINDIR)/$(EXEC) 

$(BINDIR)/$(EXEC): $(OBJECTS)
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
	/bin/rm -rf $(BINDIR)/$(EXEC)

re: fclean all
