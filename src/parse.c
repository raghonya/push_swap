/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:20:32 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:20:33 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	plus_minus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		err_push ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]));
		i++;
		err_push ((s[i] == '+' || s[i] == '-') && ft_isdigit(s[i - 1]));
	}
}

char	**create_nums(int argc, char **argv)
{
	char	**nums;
	char	*join;
	int		i;

	i = 1;
	join = "";
	while (i < argc)
		join = ft_strjoin (join, argv[i++]);
	i = -1;
	while (join[++i])
	{
		err_push(join[i] != '+' && join[i] != '-' \
		&& join[i] != ' ' && join[i] != '\n' \
		&& join[i] != '\t' && !ft_isdigit(join[i]));
	}
	plus_minus(join);
	i = -1;
	while (join[++i])
		if (join[i] == '\n' || join[i] == '\t')
			join[i] = ' ';
	nums = ft_split (join, ' ');
	err_push(!nums);
	free(join);
	return (nums);
}

void	check_ascend_2(t_stack *a)
{
	int	flag;

	flag = 0;
	while (a->next)
	{
		if (!(a->value > a->prev->value && a->value < a->next->value))
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		exit (0);
}

void	check_ascend(t_stack *a)
{
	int		size;

	size = lstsize(a);
	if (size < 2)
		exit (0);
	if (size == 2)
	{
		if (a->value < a->next->value)
			exit(0);
		return ;
	}
	check_ascend_2(a->next);
}

void	check_args(t_stack **a, int argc, char **argv)
{
	t_stack	*new;
	char	**nums;
	int		i;

	nums = create_nums(argc, argv);
	i = -1;
	while (nums[++i])
	{
		new = malloc(sizeof(t_stack));
		err_push(!new);
		new->value = ft_atol(nums[i]);
		new->next = NULL;
		nodeadd_back(a, new);
		check_back(*a, new->value);
	}
	check_ascend(*a);
	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
}
