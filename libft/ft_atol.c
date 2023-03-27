/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:36:44 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/22 14:36:45 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	err_push_for_lib(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		exit(1);
	}
}

long	ft_atol(char *str)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	err_push_for_lib (ft_strlen(str) > 10);
	while (ft_isdigit(*str))
		num = num * 10 + (*(str++) - 48);
	if (sign == -1 && num == 2147483648)
		return (sign * num);
	err_push_for_lib (num > INT_MAX || num < INT_MIN);
	return (sign * num);
}
