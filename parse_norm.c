#include <push_swap.h>

void	nodeadd_back(t_stack **head, t_stack *new)
{
	t_stack	*a;

	err_push(!head);
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
		return ;
	}
	a = *head;
	while ((*head)->next)
		*head = (*head)->next;
	new->prev = *head;
	(*head)->next = new;
	*head = a;
}

int	lstsize(t_stack *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

void	check_ascend_2(t_stack *a)
{
	int	flag;

	flag = 0;
	while (a->next)
	{
		if (!(a->value > a->prev->value && a->value < a->next->value))
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		exit (0);
}
