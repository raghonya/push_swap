#include <push_swap.h>

static int	swap(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!head || !*head || !(*head)->next)
		return (0);
	tmp = (*head)->next;
	
	(*head)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *head;
	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
	return (1);
}

void	swap_a(t_stack **head)
{
	if (swap(head))
		ft_printf ("sa\n");
}

void	swap_b(t_stack **head)
{
	if (swap(head))
		ft_printf ("sb\n");
}

void	ss(t_stack **h1, t_stack **h2)
{
	swap_a(h1);
	swap_b(h2);
}