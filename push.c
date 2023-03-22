#include <push_swap.h>

static int	push(t_stack **h1, t_stack **h2)
{
	t_stack	*tmp;

	if (!(*h1) || !h1)
		return (0);
	tmp = (*h1)->next;
	tmp->prev = NULL;
	(*h1)->next = *h2;
	(*h2)->prev = *h1;
	*h2 = *h1;
	*h1 = tmp;
	return (1);
}

void	push_a(t_stack **h1, t_stack **h2)
{
	if (push(h2, h1))
		ft_printf ("pa\n");
}

void	push_b(t_stack **h1, t_stack **h2)
{
	if (push(h1, h2))
		ft_printf ("pa\n");
}
