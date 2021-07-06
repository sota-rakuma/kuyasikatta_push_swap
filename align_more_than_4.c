/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_more_than_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:32:50 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/06 18:45:26 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first = boundary
void	get_stack_b(t_bcl *first, t_bcl *last, t_cmd *cmd, int median)
{
	t_bcl	*head;
	t_bcl	*bcl;
	t_bcl	*min;
	t_bcl	*all_min;

	bcl = set_boundary(first);
	min = find_min(first, last);
	while (min->value <= median)
	{
		head = first->next;
		all_min = find_min(bcl, last);
		if (median < head->value || (median == INT_MAX && head == all_min))
			ra(bcl, cmd);
		else if (median != INT_MAX && bcl->prev->value < median)
			rra(bcl, cmd);
		else
		{
			pb(bcl, cmd);
			if (!head->prev->nil && median != INT_MAX && head == all_min)
				rb(bcl, cmd);
		}
		min = find_min(first, last);
		if (first->next == last)
			break ;
	}
}

void	align_less_6(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd)
{
	t_bcl	*head;
	t_bcl	*median;

	median = calc_median(boundary, bcl);
	get_stack_b(boundary, bcl, cmd, median->value);
	asecnding_less_3(boundary, bcl, cmd, 0);
	asecnding_less_3(bcl, boundary, cmd, 1);
	head = bcl->next;
	while (head != boundary)
	{
		pa(bcl, cmd);
		head = bcl->next;
	}
}

int	dividing_sort(t_bcl *bcl, t_bcl *median, t_cmd *cmd, int cnt)
{
	t_bcl	*last;
	t_bcl	*target;
	t_bcl	*min;

	last = set_boundary(bcl);
	target = last->prev;
	min = find_min(bcl, last);
	if (last->next == find_min(bcl, set_last(last, cnt)))
	{
		ra(bcl, cmd);
		cnt--;
	}
	else if (median->value < target->value || target == min)
	{
		pa(bcl, cmd);
		cnt++;
	}
	else if (target->prev == min
		&& target == find_next_min(bcl, last, (long)min->value))
		sb(bcl, cmd);
	else if (min == bcl->next)
		rrb(bcl, cmd);
	else
		rb(bcl, cmd);
	return (cnt);
}

void	quick_sort(t_bcl *first, t_bcl *last, t_cmd *cmd)
{
	t_bcl	*median_b;
	t_bcl	*max;
	int		cnt;
	int		size;

	size = ft_lstsize(first, last);
	if (size <= 1)
		return (proc_remains_less_1(first, cmd, size));
	cnt = 0;
	median_b = calc_median(first, last);
	max = find_max(first, last);
	while (!last->prev->nil && (median_b->value < max->value))
	{
		if (!first->next->nil && size < 4
			&& last->prev != find_max(first, last))
			desecnding_less_3(first, last, cmd, 1);
		cnt = dividing_sort(first, median_b, cmd, cnt);
		max = find_max(first, last);
	}
	quick_sort(first, last, cmd);
	cnt = proc_remains_less_5(first, last, cmd, cnt);
	pop_back(first, last, cmd, cnt);
	quick_sort(first, last, cmd);
}

void	align_more_7(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*min;
	t_bcl	*boundary;
	t_bcl	*median;

	boundary = set_boundary(bcl);
	min = find_min(boundary, bcl);
	median = calc_median(boundary, bcl);
	get_stack_b(boundary, bcl, cmd, median->value);
	quick_sort(bcl, boundary, cmd);
	get_stack_b(boundary, min, cmd, INT_MAX);
	quick_sort(bcl, boundary, cmd);
}
