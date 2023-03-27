#include <push_swap.h>

int		sq_root(int n)
{
	int	i;

	i = 1;
	while (i < n / i)
	{
		if (n > i * i && n < (i + 1) * (i + 1))
			return (i);
		i++;
	}
	return (0);
}

int		pow_2(int n)
{
	int i;

	i = 1;
	while (n--)
		i *= 2;
	return (i);
}

int		log_2(int n)
{
	int	i;

	i = 0;
	while (1)
		if (n >= pow_2(++i) && n < pow_2(i + 1))
			return (i);
}

void	max_finder(t_stack **head)
{
	t_stack	*tmp;
	int		max;

	tmp = *head;
	max = (*head)->value;
	while (*head)
	{
		if (max < (*head)->value)
			max = (*head)->value;
		*head = (*head)->next;
	}
	*head = tmp;
	while (tmp->value != max)
		tmp = tmp->next;
	shortest_way_b(head, tmp);

}

void	sort_butterfly(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size;
	int		op;
	int		i;

	i = 0;
	size = lstsize(*a);
	op = sq_root(size) + log_2(size);
	while (i < size)
	{
		//0->i, i->i+op
		if ((*a)->index <= i)
		{
			push_b(a, b);
			rotate_b(b);
			i++;
		}
		else if ((*a)->index > i && (*a)->index <= i + op)
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
	while (*b)
	{
		max_finder(b);
		push_a(a, b);
	}
}