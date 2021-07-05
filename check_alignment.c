/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:29:32 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:04:29 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// B first = guard, last = boundary
// A first = boundary, last = guard
// specifier -1 b(descending), 0 last(ascending), 1 a(ascending)
int	check_alignment(t_bcl *first, t_bcl *last, int specifier)
{
	t_bcl	*bcl;

	if (specifier == 0 && first->prev != last)
		return (0);
	bcl = first->next;
	while (bcl->next != last)
	{
		if (specifier == -1 && bcl->value < bcl->next->value)
			return (0);
		else if (specifier != -1 && bcl->value > bcl->next->value)
			return (0);
		bcl = bcl->next;
	}
	return (1);
}
