/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:45:45 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/09 13:33:47 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i + 1] == sep || !(str[i + 1])) && str[i] != sep)
			words++;
		i++;
	}
	return (words);
}

static char	**ft_process(char **list, const char *s, char c)
{
	unsigned int	i;
	size_t			j;
	size_t			word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c)
				j++;
			list[word] = ft_substr(s, i, j);
			i += j;
			word++;
		}
	}
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		words;

	words = ft_word_count(s, c);
	list = (char **) malloc(sizeof(char *) * (words + 1));
	if (list == NULL)
		return (NULL);
	list = ft_process(list, s, c);
	list[words] = 0;
	return (list);
}
/*
int	main(int argc, char **argv)
{

	if (argc == 3)
	{
		int i = 0;
		char **result = ft_split(argv[1], argv[2][0]);
		while (result[i])
		{
			printf("%s\n" , result[i]);
			i++;
		}
		free(result);
		return (0);
	}
	else
		return (1);
}*/