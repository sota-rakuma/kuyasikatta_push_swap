/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:57:31 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/24 14:30:26 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_bcl **lst, t_bcl *new)
{
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
