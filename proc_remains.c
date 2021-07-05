/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_remains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:13:01 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 18:21:07 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	proc_remains_less_5(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd, int num)
{
	t_bcl	*min;
	t_bcl	*last;
	t_bcl	*median;

	if (!bcl->next->nil || num > 5)
		return (num);
	last = set_last(bcl, num + 1);
	median = calc_median(boundary, last);
	while (boundary->next != last)
	{
		min = find_min(bcl, last);
		if (boundary->next == min)
			ra(bcl, cmd);
		else if (!bcl->next->nil && boundary->prev == min)
			pa(bcl, cmd);
		else if (num > 2 && median->value <= boundary->next->value
			&& boundary->next->next != min)
			pb(bcl, cmd);
		else if (!boundary->prev->nil && !boundary->prev->prev->nil
			&& boundary->prev->prev->value < boundary->prev->value)
			sb(bcl, cmd);
		else
			sa(bcl, cmd);
	}
	return (0);
}

void	pop_back(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd, int num)
{
	t_bcl	*last;
	t_bcl	*min;

	if (num < 6)
		return ;
	last = set_last(boundary, num);
	min = find_min(boundary, last);
	while (boundary->next != last)
	{
		min = find_min(bcl, last);
		if (!boundary->prev->nil && boundary->prev == min)
			pa(bcl, cmd);
		if (boundary->next == min)
			ra(bcl, cmd);
		else
			pb(bcl, cmd);
	}
}

void	proc_remains_less_1(t_bcl *bcl, t_cmd *cmd, int size)
{
	if (size < 1)
		return ;
	else if (size == 1)
	{
		pa(bcl, cmd);
		ra(bcl, cmd);
		return ;
	}
}
