/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:20:25 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:20:26 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pomoshnik(int *arr, t_index a, t_arr *left, t_arr *right)
{
	a.i = 0;
	a.j = 0;
	while (a.i < left->size && a.j < right->size)
	{
		if (left->a[a.i] < right->a[a.j])
			arr[(a.k)++] = left->a[(a.i)++];
		else
			arr[(a.k)++] = right->a[(a.j)++];
	}
	while (a.i < left->size)
		arr[(a.k)++] = left->a[(a.i)++];
	while (a.j < right->size)
		arr[(a.k)++] = right->a[(a.j)++];
}

void	kpcn(int *arr, int beg, int mid, int end)
{
	t_arr	left;
	t_arr	right;
	t_index	a;

	a.i = -1;
	a.j = -1;
	a.k = beg;
	left.a = malloc(sizeof(int) * mid - beg + 1);
	right.a = malloc(sizeof(int) * end - mid);
	left.size = mid - beg + 1;
	right.size = end - mid;
	while (++(a.i) < mid - beg + 1)
		left.a[a.i] = arr[beg + a.i];
	while (++(a.j) < end - mid)
		right.a[a.j] = arr[mid + a.j + 1];
	pomoshnik(arr, a, &left, &right);
	free(right.a);
	free(left.a);
}

void	voreve_sort(int *arr, int beg, int end)
{
	int	mid;

	if (beg < end)
	{
		mid = (beg + end) / 2;
		voreve_sort(arr, beg, mid);
		voreve_sort(arr, mid + 1, end);
		kpcn(arr, beg, mid, end);
	}
}

void	indexing_final(t_stack **a, t_arr arr)
{
	int	i;

	while (*a)
	{
		i = -1;
		while (++i < arr.size)
			if (arr.a[i] == (*a)->value)
				break ;
		(*a)->index = i;
		*a = (*a)->next;
	}
}

void	indexing(t_stack **a)
{
	t_stack	*tmp;
	t_arr	arr;
	int		i;

	i = -1;
	tmp = *a;
	arr.size = lstsize(*a);
	arr.a = malloc(sizeof(int) * arr.size);
	while (*a)
	{
		arr.a[++i] = (*a)->value;
		*a = (*a)->next;
	}
	*a = tmp;
	voreve_sort(arr.a, 0, arr.size - 1);
	indexing_final(a, arr);
	*a = tmp;
}
