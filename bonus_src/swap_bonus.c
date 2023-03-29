/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:22:00 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:22:02 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *head;
	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

void	swap_a(t_stack **head)
{
	swap(head);
}

void	swap_b(t_stack **head)
{
	swap(head);
}

void	swap_ab(t_stack **h1, t_stack **h2)
{
	swap_a(h1);
	swap_b(h2);
}
