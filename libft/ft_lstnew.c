/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:12:20 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/25 15:19:29 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bcl	*ft_lstnew(int content)
{
	t_bcl	*lst;

	lst = (t_bcl *)malloc(sizeof(t_bcl));
	if (lst == NULL)
		return (NULL);
	lst->value = content;
	lst->nil = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
