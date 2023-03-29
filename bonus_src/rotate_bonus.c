/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:30 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:30 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*head) || !(*head)->next || !head)
		return ;
	tmp = *head;
	tmp2 = (*head)->next;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = *head;
	tmp->next = NULL;
	*head = tmp2;
}

void	rotate_a(t_stack **head)
{
	rotate(head);
}

void	rotate_b(t_stack **head)
{
	rotate(head);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
