/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:15:58 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/30 20:15:58 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	err_push(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

void	is_ko(int a)
{
	if (a)
	{
		ft_printf("KO\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	char	*(instr[12]);
	char	*input;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	fill(instr);
	check_args(&a, argc, argv);
	input = get_next_line(0);
	while (input)
	{
		check_input(input, instr);
		checking(&a, &b, input);
		input = get_next_line(0);
	}
	is_ko(!a || b);
	while (a->next)
	{
		is_ko(a->value > a->next->value);
		a = a->next;
	}
	ft_printf ("OK\n");
	return (0);
}
