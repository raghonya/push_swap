/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:10 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:11 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	err_push(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	check_args(&a, argc, argv);
	size = lstsize(a);
	indexing(&a);
	if (size == 2)
		swap_a(&a);
	else if (size > 2 && size < 13)
		sort_under_12(&a, &b, size);
	else
		sort_butterfly(&a, &b, size);
	return (0);
}
