///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   sort_butterfly.c                                   :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/03/29 20:21:38 by raghonya          #+#    #+#             */
///*   Updated: 2023/03/29 20:21:39 by raghonya         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

#include <push_swap.h>

//int		sq_root(int n)
//{
//	int	i;

//	i = 1;
//	while (1)
//	{
//		if (n > i * i && n < (i + 1) * (i + 1))
//			return (i);
//		i++;
//	}
//	return (0);
//}

//int		pow_2(int n)
//{
//	int i;

//	i = 1;
//	while (n--)
//		i *= 2;
//	return (i);
//}

//int		log_2(int n)
//{
//	int	i;

//	i = 0;
//	while (1)
//		if (n >= pow_2(++i) && n < pow_2(i + 1))
//			return (i);
//}

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

void	pushing(t_stack **a, t_stack **b, int size)
{
	int	op;
	int	i;

	i = 0;
	op = sq_root(size) + log_2(size);
	while (i < size)
	{
		if ((*a)->index <= i)
		{
			push_b(a, b);
			rotate_b(b);
			i += 1;
		}
		else if ((*a)->index > i && (*a)->index <= i + op)
		{
			push_b(a, b);
			i += 1;
		}
		else
			rotate_a(a);
	}
}

void	sort_butterfly(t_stack **a, t_stack **b, int size)
{
<<<<<<< HEAD
	int		size;
	
	size = lstsize(*a);
	pushing(a, b, size);
=======
	int		i;

	i = 0;
	while (i < size)
		pushing(a, b, &i, size);
>>>>>>> d3539be727bc3f9471ec6b9c8c2d6515f2c1607d
	while (*b)
	{
		max_finder(b);
		push_a(a, b);
	}
}
