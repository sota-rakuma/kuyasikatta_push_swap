/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:42:59 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/02 18:43:31 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bcl	*ft_lstlast(t_bcl *lst)
{
	if (lst == 0)
		return (0);
	while (!lst->next->nil)
		lst = lst->next;
	return (lst);
}
