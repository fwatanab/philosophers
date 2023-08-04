NAME	= philosophers

SRCSDIR	= src/

SRCS = main.c

OBJS	= $(addprefix $(SRCSDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFTDIR	= libft/
LIBFTNAME	= libft.a

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(LIBFTDIR)$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
