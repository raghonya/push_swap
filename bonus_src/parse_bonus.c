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
	i = -1;
	while (join[++i])
		if (join[i] == '\n' || join[i] == '\t')
			join[i] = ' ';
	nums = ft_split (join, ' ');
	err_push(!nums);
	free(join);
	return (nums);
}

void	check_back(t_stack *a, int tiv)
{
	while (a->next)
	{
		err_push (a->value == tiv);
		a = a->next;
	}
}

void	check_args(t_stack **a, int argc, char **argv)
{
	t_stack	*new;
	char	**nums;
	int		i;

	if (argc == 1)
		exit(0);
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
	if (!*a)
		exit(0);
	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
}
