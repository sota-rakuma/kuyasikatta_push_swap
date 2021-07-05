/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_or_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 01:30:02 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:33:28 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bcl	*find_next_min(t_bcl *first, t_bcl *last, long min)
{
	t_bcl	*median;
	t_bcl	*tmp;

	tmp = first;
	median = tmp->next;
	if (median->nil)
		median = median->next;
	while (!first->next->next->nil && (long)median->value <= min)
		median = median->next;
	tmp = median;
	while (tmp != last)
	{
		if (!tmp->nil
			&& min < (long)tmp->value && tmp->value < median->value)
			median = tmp;
		tmp = tmp->next;
	}
	return (median);
}

t_bcl	*find_max(t_bcl *first, t_bcl *last)
{
	t_bcl	*max;
	t_bcl	*tmp;

	max = first->next;
	if (max->nil)
		max = max->next;
	tmp = max;
	while (tmp != last)
	{
		if (!tmp->nil && max->value < tmp->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_bcl	*find_min(t_bcl *first, t_bcl *last)
{
	t_bcl	*min;
	t_bcl	*tmp;

	min = first->next;
	if (min->nil)
		min = min->next;
	tmp = min;
	while (tmp != last)
	{
		if (!tmp->nil && tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
