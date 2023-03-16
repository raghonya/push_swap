#include <push_swap.h>

static int	swap(t_stack **head)
{
	t_stack	*tmp;
	int		res;

	res = (!head || !*head || !(*head)->next);
	if (!res)
	{
		tmp = (*head)->next;
		(*head)->next = tmp->next;
		tmp->next = *head;
		if (tmp->next)
			tmp->next->prev = *head;
		(*head)->prev = tmp;
		tmp->prev = NULL;
		*head = tmp;
	}
	return (res);
}

void	swap_a(t_stack **head)
{
	if (!swap(head))
		ft_printf ("sa\n");
}

void	swap_b(t_stack **head)
{
	if (!swap(head))
		ft_printf ("sb\n");
}
