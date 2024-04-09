/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:44:44 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/09 16:46:39 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	j = 0;
	n_len = ft_strlen(little);
	if (!(little[j]) || !n_len)
		return ((char *)big);
	if (!len)
		return (0);
	i = 0;
	while (big[i] && i <= len - n_len)
	{
		while (big[i + j] == little[j])
		{
			if (!(little[j + 1]))
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
