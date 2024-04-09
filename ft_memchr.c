/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:36:46 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/09 13:32:13 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		chr;

	i = 0;
	src = (const unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == chr)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
