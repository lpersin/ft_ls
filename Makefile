CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft
LDFLAGS = -L./libft -lft

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
EXEC = ft_ls

all: $(BINDIR)/$(EXEC) 

$(BINDIR)/$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	/bin/rm -rf $(OBJECTS)

fclean: clean
	/bin/rm -rf $(BINDIR)/$(EXEC)

re: fclean all
