#include <push_swap_bonus.h>

void	checking(t_stack **a, t_stack **b, char *input)
{
	if (!ft_strcmp(input, "pa\n"))
		push_a(a, b);
	else if (!ft_strcmp(input, "pb\n"))
		push_b(a, b);
	else if (!ft_strcmp(input, "sa\n"))
		swap_a(a);
	else if (!ft_strcmp(input, "sb\n"))
		swap_b(b);
	else if (!ft_strcmp(input, "ss\n"))
		swap_ab(a, b);
	else if (!ft_strcmp(input, "ra\n"))
		rotate_a(a);
	else if (!ft_strcmp(input, "rb\n"))
		rotate_b(b);
	else if (!ft_strcmp(input, "rr\n"))
		rotate_ab(a, b);
	else if (!ft_strcmp(input, "rra\n"))
		rrotate_a(a);
	else if (!ft_strcmp(input, "rrb\n"))
		rrotate_b(b);
	else if (!ft_strcmp(input, "rrr\n"))
		rrotate_ab(a, b);
}