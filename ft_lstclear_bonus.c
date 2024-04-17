/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:51:50 by oohnivch          #+#    #+#             */
/*   Updated: 2024/04/16 17:29:34 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;

	if (!lst || !del || !(*lst))
		return ;
	n = (*lst)->next;
	if (n != NULL)
		ft_lstclear(&n, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
