#include <push_swap.h>

 int	rotate(t_stack **head)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!(*head) || !(*head)->next || !head)
		return (0);
	tmp = *head;
	tmp2 = (*head)->next;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = *head;
	tmp->next = NULL;
	*head = tmp2;
	return (1);
}

void	rotate_a(t_stack **head)
{
	if (rotate(head))
		ft_printf ("ra\n");
}

void	rotate_b(t_stack **head)
{
	if (rotate(head))
		ft_printf ("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
