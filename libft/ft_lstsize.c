/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:33:16 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:05:32 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_bcl *first, t_bcl *last)
{
	t_bcl	*head;
	int		len;

	if (first == 0)
		return (0);
	len = 0;
	head = first->next;
	while (head != last)
	{
		len++;
		head = head->next;
	}
	return (len);
}
