/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:10 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/25 15:17:46 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_bcl **lst, void (*del)(int))
{
	t_bcl	*tmp;

	if (lst == 0)
		return ;
	while ((*lst)->value)
	{
		tmp = (*lst)->prev;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	ft_lstdelone(*lst, del);
	lst = 0;
}
