/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:44:44 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/04 13:49:58 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	j = 0;
	if (!(needle[j]) || len == 0)
		return (haystack);
	n_len = 0;
	while (needle[n_len])
		n_len++;
	i = 0;
	while (haystack[i] && i <= len - n_len)
	{
		while (haystack[i + j] == needle[j])
		{
			if (!(needle[j + 1]))
				return (haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
