/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_butterfly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:38 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:39 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sq_root(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i - 1);
}

int	log_2(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 2;
		i ++;
	}
	return (i);
}

void	max_finder(t_stack **head)
{
	t_stack	*tmp;
	int		max;
	int		i;

	i = 0;
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
	{
		tmp = tmp->next;
		i++;
	}
	shortest_way_b(head, tmp, i);
}

void	pushing(t_stack **a, t_stack **b, int *i, int size)
{
	int	op;

	op = sq_root(size) + log_2(size) - 1;
	if ((*a)->index <= *i)
	{
		push_b(a, b);
		rotate_b(b);
		*i += 1;
	}
	else if ((*a)->index > *i && (*a)->index <= *i + op)
	{
		push_b(a, b);
		*i += 1;
	}
	else
		rotate_a(a);
}

void	sort_butterfly(t_stack **a, t_stack **b)
{
	int		size;
	int		i;

	i = 0;
	size = lstsize(*a);
	while (i < size)
		pushing(a, b, &i, size);
	while (*b)
	{
		max_finder(b);
		push_a(a, b);
	}
}
