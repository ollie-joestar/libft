/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:44 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/09 14:07:13 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i = 2;
	while (n > 9 || n < -9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	ft_putnbr(int n, char *str)
{
	unsigned int	num;
	int				neg;
	int				i;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == 0)
		str[i++] = '0';
	num = (1 - 2 * neg) * (unsigned int)n;
	while (num > 0)
	{
		str[i++] = '0' + (num % 10);
		num = n / 10;
	}
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
}

static void	reverse(char *str)
{
	char	temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = ft_calc(n);
	ptr = malloc ((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_putnbr(n, ptr);
	reverse(ptr);
	return (ptr);
}
