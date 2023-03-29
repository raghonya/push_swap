/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:20 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:22 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	rrotate(t_stack **head)
{
	t_stack	*tmp;

	if (!(*head) || !(*head)->next || !head)
		return ;
	tmp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->prev->next = NULL;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void	rrotate_a(t_stack **head)
{
	rrotate(head);
}

void	rrotate_b(t_stack **head)
{
	rrotate(head);
}

void	rrotate_ab(t_stack **a, t_stack **b)
{
	rrotate_a(a);
	rrotate_b(b);
}
