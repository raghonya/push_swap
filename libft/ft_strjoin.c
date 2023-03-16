/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:21:11 by raghonya          #+#    #+#             */
/*   Updated: 2023/01/16 16:22:22 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*brat(const char *s1, const char *s2, size_t s1len, size_t s2len)
{
	size_t	i;
	int		k;
	char	*s;

	i = 0;
	k = 0;
	s = malloc(s1len + s2len + 2);
	if (!s)
		return (NULL);
	while (i < s1len + s2len)
	{
		if (i < s1len)
			s[i] = s1[i];
		else
			s[i] = s2[k++];
		i++;
	}
	s[i++] = ' ';
	s[i] = 0;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = brat(s1, s2, s1len, s2len);
	if (!s)
		return (NULL);
	if (*s1)
		free((char *)s1);
	return (s);
}
