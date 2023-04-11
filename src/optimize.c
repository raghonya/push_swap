/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_butterfly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:21:38 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:39 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sq_root(int n)
{
	int	i;

	i = 1;
	while (1)
	{
		if (n > i * i && n < (i + 1) * (i + 1))
			return (i);
		i++;
	}
	return (0);
}

int		pow_2(int n)
{
	int i;

	i = 1;
	while (n--)
		i *= 2;
	return (i);
}

int		log_2(int n)
{
	int	i;

	i = 0;
	while (1)
		if (n >= pow_2(++i) && n < pow_2(i + 1))
			return (i);
}
