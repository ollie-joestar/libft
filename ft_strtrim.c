/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:12 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/04 15:03:51 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && check(s1[start], set))
		start++;
	while (end > start && check(s1[end], set))
		end--;
	size = end - start;
	ptr = malloc ((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	size = 0;
	while (start + size <= end)
	{
		ptr[size] = s1[start + size];
		size++;
	}
	ptr[size] = '\0';
	return (ptr);
}
