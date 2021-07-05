/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:50:33 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/25 15:18:02 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bcl	*ft_lstmap(t_bcl *lst, int (*f)(int), void (*del)(int))
{
	t_bcl	*new;
	t_bcl	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->value));
		if (tmp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
