#include <push_swap.h>

void	swap_a(t_stack *a)
{
	int	tmp;

	tmp = a->value;
	a->value = a->next;
}