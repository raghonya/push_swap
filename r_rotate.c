#include <push_swap.h>

int	rrotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*head) || !(*head)->next || !head)
		return (0);
	tmp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->prev->next = NULL;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
	return (1);
}

void	rrotate_a(t_stack **head)
{
	if (rrotate(head))
		ft_printf ("rra\n");
}

void	rrotate_b(t_stack **head)
{
	if (rrotate(head))
		ft_printf ("rrb\n");
}
