/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:51:29 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 18:20:16 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bcl	*set_last(t_bcl *start, int cnt)
{
	t_bcl	*last;

	last = start->next;
	while (cnt-- > 0)
		last = last->next;
	return (last);
}

t_bcl	*calc_median(t_bcl *first, t_bcl *last)
{
	int		median;
	long	min;
	t_bcl	*head;
	t_bcl	*pivot;

	median = (1 + ft_lstsize(first, last)) / 2;
	head = first->next;
	min = LONG_MIN;
	while (median-- > 0)
	{
		pivot = find_next_min(first, last, min);
		min = (long)pivot->value;
	}
	return (pivot);
}

t_bcl	*set_boundary(t_bcl *bcl)
{
	int	cnt;

	cnt = 0;
	while (cnt < 1)
	{
		bcl = bcl->next;
		if (bcl->nil)
			cnt++;
	}
	return (bcl);
}
