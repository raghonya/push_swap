/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:22:51 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:22:58 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <stdio.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
}	t_index;

typedef struct s_arr
{
	int	*a;
	int	size;
}	t_arr;

void	err_push(int a);
void	print(t_stack *a);
void	check_args(t_stack **a, int argc, char **argv);
void	nodeadd_back(t_stack **head, t_stack *new);
int		lstsize(t_stack *a);
void	indexing(t_stack **a);
void	check_ascend_2(t_stack *a);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **head, t_stack **head2);
void	push_a(t_stack **head1, t_stack **head2);
void	push_b(t_stack **head1, t_stack **head2);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **head, t_stack **head2);
void	rrotate_a(t_stack **head);
void	rrotate_b(t_stack **head);
void	rrotate_ab(t_stack **head, t_stack **head2);
void	sort_under_12(t_stack **a, t_stack **b, int size_a);
void	sort_butterfly(t_stack **a, t_stack **b);
void	shortest_way_a(t_stack **head, t_stack *val);
void	shortest_way_b(t_stack **head, t_stack *val, int i);

#endif
