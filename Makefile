NAME = libft.a
SRC = get_next_line_utils.c	get_next_line.c	get_next_line.h	main.c
BNS = get_next_line_bonus.c	get_next_line_bonus.h	get_next_line_utils_bonus.c


OBJ = $(SRC:.c=.o)

OBJ_B = $(BNS:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all: $(NAME) 

$(NAME) : $(OBJ)
	ar -rc	$(NAME) $(OBJ)

%.o : %.c get_next_line
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean:
	rm -f $(OBJ) $(OBJ_B) $(NAME)

re	: fclean	all

bonus:	$(OBJ) $(OBJ_B)	get_next_line_bonus.h
	ar -rc	$(NAME) $(OBJ) $(OBJ_B)