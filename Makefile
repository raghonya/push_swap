NAME	=	push_swap

CFLAGS	=	#-fsanitize=address -glldb# -Wall -Wextra -Werror

DEP		=	Makefile push_swap.h

FILES	=	push_swap.c \
			parse.c \
			

LIB		=	./libft

PLIB	=	./Printf

IFLAGS	=	-I$(LIB) -I$(PLIB) -I./

LFLAGS	=	-L$(PLIB) -lftprintf -L$(LIB) -lft

OBJS	=	$(FILES:.c=.o)

all: libs $(NAME)

%.o: %.c $(DEP)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME)

clean: libs
	rm -f *.o

fclean: clean
	rm -f $(NAME)

libs:
	@$(MAKE) $(MAKECMDGOALS) -C $(LIB)
	@$(MAKE) $(MAKECMDGOALS) -C $(PLIB)

re:	fclean all

.PHONY: all clean fclean re run_libs