/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:01:43 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/04 14:05:34 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total_size;
	void			*ptr;
	unsigned char	*char_ptr;

	if (nmemb == 0 || size == 0 || 2147483647 / size < nmemb)
		return (NULL);
	total_size = size * nmemb;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		char_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
