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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

#endif
