/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:20:42 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:20:43 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		*head = (*head)->next;
	}
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

void	check_back(t_stack *a, int tiv)
{
	while (a->next)
	{
		err_push (a->value == tiv);
		a = a->next;
	}
}
