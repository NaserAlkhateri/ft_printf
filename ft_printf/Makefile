CFLAGS = -Wall -Werror -Wextra
SOURCES = 	ft_printf.c ft_put_itoa.c ft_put_utoa.c ft_putchar_int.c\
			ft_putptr.c ft_putstr_int.c ft_strlen.c
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	ar rcs	$@ $^ $(NAME)


clean:
	rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all