/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_12.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:48 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:48 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	shortest_way_a(t_stack **head, t_stack *val)
{
	t_stack	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = *head;
	size = lstsize(*head);
	while ((*head)->value != val->value)
	{
		i++;
		*head = (*head)->next;
	}
	*head = tmp;
	if (i < size / 2)
		while ((*head)->value != val->value)
			rotate_a(head);
	else
		while ((*head)->value != val->value)
			rrotate_a(head);
}

void	shortest_way_b(t_stack **head, t_stack *val, int i)
{
	if (i < lstsize(*head) / 2)
		while ((*head)->value != val->value)
			rotate_b(head);
	else
		while ((*head)->value != val->value)
			rrotate_b(head);
}

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
			shortest_way_a(a, tmp);
			push_b(a, b);
		}
	}
	sort_3(a);
	while (*b)
		push_a(a, b);
}
