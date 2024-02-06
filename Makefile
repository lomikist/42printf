NAME = libftprintf.a

SRCS =  ft_printf.c

SURPL_O = ft_printf.o 

CC = cc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)


all : $(NAME)


$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.c : %.o
	$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
