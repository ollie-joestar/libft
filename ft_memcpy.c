/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:58:03 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/04 13:02:10 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n && (s[i]))
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
