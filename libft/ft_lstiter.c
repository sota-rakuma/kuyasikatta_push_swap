/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:24:00 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/25 15:17:53 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_bcl *lst, void (*f)(int))
{
	if (lst == 0 && !f)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}
