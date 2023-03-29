NAME	=	push_swap

NAME_BONUS	=	checker

CFLAGS	=	#-Wall -Wextra -Werror

f		=	#-fsanitize=address -g

DEP		=	Makefile ./includes/push_swap.h

FILES	=	src/push_swap.c \
			src/parse.c \
			src/parse_norm.c \
			src/push.c \
			src/swap.c \
			src/rotate.c \
			src/r_rotate.c \
			src/indexing.c \
			src/sort_under_12.c \
			src/sort_butterfly.c 

BONUS	=	bonus_src/checker_bonus.c \
			bonus_src/checking_bonus.c \
			bonus_src/parse_bonus.c \
			bonus_src/parse_norm_bonus.c \
			bonus_src/push_bonus.c \
			bonus_src/swap_bonus.c \
			bonus_src/rotate_bonus.c \
			bonus_src/r_rotate_bonus.c 

LIB		=	./libft

PLIB	=	./Printf

IFLAGS	=	-I$(LIB) -I$(PLIB) -I./includes

LFLAGS	=	-L$(PLIB) -lftprintf -L$(LIB) -lft

OBJS	=	$(FILES:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

CMD	=	$(MAKECMDGOALS)

ifeq ($(shell uname -s), MINGW64_NT-6.1-7601)
CC	=	gcc
endif

ifeq ($(MAKECMDGOALS), bonus)
	CMD	=	all
	DEP = Makefile ./includes/push_swap_bonus.h
endif

all: libs $(NAME)

libs:
	@$(MAKE) $(CMD) -C $(LIB)
	@$(MAKE) $(CMD) -C $(PLIB)

%.o: %.c $(DEP) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(f) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)

bonus: libs $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(f) $(OBJS_BONUS) $(IFLAGS) $(LFLAGS) -o $(NAME_BONUS)

clean: libs
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re libs bonus