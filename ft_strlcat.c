/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:20:05 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/09 15:38:05 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	offset;
	size_t	index;
	size_t	len;

	index = 0;
	offset = ft_strlen(dest);
	len = ft_strlen(src);
	if (size == 0 || size <= offset)
		return (len + size);
	while (index <= len && index + offset < size - 1)
	{
		dest[offset + index] = src[index];
		index++;
	}
	dest[offset + index] = 0;
	return (len + offset);
}
