#include <push_swap.h>

void	sort_3(t_stack **a)
{
	if ((*a)->value < (*a)->next->next->value \
		&& (*a)->value < (*a)->next->value)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if ((*a)->value < (*a)->next->next->value \
		&& (*a)->value > (*a)->next->value)
		swap_a(a);
	else if ((*a)->value > (*a)->next->next->value \
		&& (*a)->value < (*a)->next->value)
		rrotate_a(a);
	else if ((*a)->value > (*a)->next->value \
		&& (*a)->value > (*a)->next->next->value \
		&& (*a)->next->value < (*a)->next->next->value)
		rotate_a(a);
	else
	{
		swap_a(a);
		rrotate_a(a);
	}
}

void	shortest_way();

void	sort_under_12(t_stack **a, t_stack **b, int size_a)
{
	t_stack	*tmp;
	int		ind;

	if (size_a > 3)
	{
		ind = 0;
		while (size_a != 3)
		{
			tmp = *a;
			while (ind != tmp->index)
				tmp = tmp->next;
			ind++;
			size_a--;
			while ((*a)->index != tmp->index)
				rotate_a(a);
			push_b(a, b);
		}
	}
	sort_3(a);
	while (*b)
		push_a(a, b);
}