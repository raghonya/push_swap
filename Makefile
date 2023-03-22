NAME	=	push_swap

CFLAGS	=	-g # -Wall -Wextra -Werror

f		=	-fsanitize=address

DEP		=	Makefile push_swap.h

FILES	=	push_swap.c \
			parse.c \
			push.c \
			swap.c \
			rotate.c \
			r_rotate.c \
			
LIB		=	./libft

PLIB	=	./Printf

IFLAGS	=	-I$(LIB) -I$(PLIB) -I./

LFLAGS	=	-L$(PLIB) -lftprintf -L$(LIB) -lft

OBJS	=	$(FILES:.c=.o)

ifeq ($(MAKECMDGOALS), bonus)
	CMD	=	all
else
	CMD	=	$(MAKECMDGOALS)
endif

all: libs $(NAME)

%.o: %.c $(DEP) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(f) $(IFLAGS) $(LFLAGS) -o $(NAME)


libs:
	@$(MAKE) $(MAKECMDGOALS) -C $(LIB)
	@$(MAKE) $(MAKECMDGOALS) -C $(PLIB)


clean: libs
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re run_libs