NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror

f		=	-fsanitize=address -g

DEP		=	Makefile push_swap.h

FILES	=	push_swap.c \
			parse.c \
			parse_norm.c \
			push.c \
			swap.c \
			rotate.c \
			r_rotate.c \
			indexing.c \
			sort_under_12.c \
			sort_butterfly.c \

BONUS	=	bonus/checker_bonus.c \
			bonus/parse_bonus.c \

LIB		=	./libft

PLIB	=	./Printf

IFLAGS	=	-I$(LIB) -I$(PLIB) -I.\

LFLAGS	=	-L$(PLIB) -lftprintf -L$(LIB) -lft

OBJS	=	$(FILES:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

ifeq ($(shell uname -s), MINGW64_NT-6.1-7601)
CC	=	gcc
endif

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
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJS_BONUS)
		$(CC) $(OBJS_BONUS) $(CFLAGS) $(f) -I../libft -I../Printf \
		-I./ -L.$(PLIB) -lftprintf -L.$(LIB) -lft -o $(NAME_BONUS)


re:	fclean all

.PHONY: all clean fclean re run_libs