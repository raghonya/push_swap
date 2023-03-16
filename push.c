#include <push_swap.h>

static int	push(t_stack **h1, t_stack **h2)
{
	t_stack	*tmp;

	tmp = (*h1)->next;
	(*h1)->next = *h2;
	(*h2)->prev = *h1;
	tmp->prev = NULL;
	*h2 = *h1;
	*h1 = tmp;
}