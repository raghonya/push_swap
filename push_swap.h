#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				index;
	int				value;
	struct	s_stack	*prev;
	struct	s_stack	*next;
}	t_stack;

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <stdio.h>

void	err_push(int a);
void	check_args(t_stack **a, int argc, char **argv);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
int		rotate(t_stack **head);
int		rrotate(t_stack **head);

#endif