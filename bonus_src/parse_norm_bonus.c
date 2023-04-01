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

#include <push_swap_bonus.h>

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

void	fill(char **s)
{
	s[0] = "pa\n";
	s[1] = "pb\n";
	s[2] = "sa\n";
	s[3] = "sb\n";
	s[4] = "ss\n";
	s[5] = "ra\n";
	s[6] = "rb\n";
	s[7] = "rr\n";
	s[8] = "rra\n";
	s[9] = "rrb\n";
	s[10] = "rrr\n";
	s[11] = NULL;
}

void	check_input(char *s, char **instr)
{
	int		flag;
	int		i;

	i = -1;
	flag = 777;
	while (instr[++i])
	{
		if (!ft_strcmp(instr[i], s))
		{
			flag = 1;
			break ;
		}
	}
	err_push(flag != 1);
}
