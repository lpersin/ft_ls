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

LIBSOURCES := $(wildcard $(LIBDIR)/*.c)
LIBOBJECTS := $(LIBSOURCES:$(LIBDIR)/%.c=$(LIBDIR)/%.o) 
LIB = libft.a

all: $(LIBDIR)/$(LIB) $(BINDIR)/$(EXEC) 

$(BINDIR)/$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB) : $(LIBOBJECTS) 
	cd $(LIBDIR) && make

$(LIBOBJECTS) :$(LIBDIR)/%.o : $(LIBDIR)/%.c

.PHONY: clean fclean re

clean:
	cd $(LIBDIR) && make clean
	/bin/rm -rf $(OBJECTS)

fclean: clean
	cd $(LIBDIR) && make fclean
	/bin/rm -rf $(BINDIR)/$(EXEC)

re: fclean all
