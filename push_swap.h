#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <stdio.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef	struct s_index
{
	int	i;
	int	j;
	int	k;
}	t_index;

typedef	struct s_arr
{
	int	*a;
	int	size;
}	t_arr;

void	err_push(int a);
void	check_args(t_stack **a, int argc, char **argv);
void	nodeadd_back(t_stack **head, t_stack *new);
int		lstsize(t_stack *a);
void	indexing(t_stack **a);
void	check_ascend_2(t_stack *a);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	push_a(t_stack **head1, t_stack **head2);
void	push_b(t_stack **head1, t_stack **head2);
int		rotate(t_stack **head);
int		rrotate(t_stack **head);

#endif