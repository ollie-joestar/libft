/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:19:01 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/04 12:48:56 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>

int	main(int argc, char** argv)
{
	if (argc != 2)
		return (1);
	else
	{
		char	c;

		c = argv[1][0];
		printf("The character is : %c\n", c);
		printf("The character is ascii : %d\n", ft_isascii(c));
		printf("The character is printable : %d\n", ft_isprint(c));
		printf("The character is alphanumeric : %d\n", ft_isalnum(c));
		printf("The character is alphabet : %d\n", ft_isalpha(c));
		printf("The character is digit : %d\n", ft_isdigit(c));
		return (0);
	}
}*/
