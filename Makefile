NAME	= philo

SRCSDIR	= src/
FT_SRCDIR = ft_utils/

SRCS = main.c check_error.c input.c philo.c philo_cycle.c time.c surveillance.c eat_utils.c

FT_SRC = ft_atoi.c ft_isalpha.c

OBJS	= $(addprefix $(SRCSDIR), $(SRCS:.c=.o))

FT_OBJS	= $(addprefix $(FT_SRCDIR), $(FT_SRC:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:$(NAME)

$(NAME):$(OBJS) $(FT_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(FT_OBJS)

fclean:
	$(RM) $(OBJS) $(FT_OBJS) $(NAME)

re: fclean all
