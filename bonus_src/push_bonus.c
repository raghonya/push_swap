/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:20:51 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:20:53 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	push(t_stack **h1, t_stack **h2)
{
	t_stack	*tmp;

	if (!(*h1) || !h1)
		return ;
	tmp = (*h1)->next;
	if (tmp)
		tmp->prev = NULL;
	if (*h2)
		(*h2)->prev = *h1;
	(*h1)->next = *h2;
	*h2 = *h1;
	*h1 = tmp;
}

void	push_a(t_stack **h1, t_stack **h2)
{
	push(h2, h1);
}

void	push_b(t_stack **h1, t_stack **h2)
{
	push(h1, h2);
}
