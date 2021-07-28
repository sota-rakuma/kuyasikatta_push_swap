/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_less_than_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:25:25 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/28 14:09:04 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	exec_cmd(t_bcl *bcl, int command, t_cmd *cmd, int spec)
{
	if (spec == 0)
	{
		if (command == 1)
			return (ra(bcl, cmd));
		else if (command == 2)
			return (rra(bcl, cmd));
		else
			return (sa(bcl, cmd));
	}
	else
	{
		if (command == 1)
			return (rrb(bcl, cmd));
		else if (command == 2)
			return (rb(bcl, cmd));
		else
			return (sb(bcl, cmd));
	}
}

// spec == 0 -> a, spec == 1 -> b	(ascending)
// a(0) -> first = boundary, last = guard
// b(1) -> first = guard, last = boundary
// 1 = ra, rrb, 2 = rra, rb, 0 = swap
void	asecnding_less_3(t_bcl *first, t_bcl *last, t_cmd *cmd, int spec)
{
	t_bcl	*head;
	t_bcl	*toe;
	int		command;

	command = -1;
	while (!check_alignment(first, last, 1))
	{
		head = first->next;
		toe = last->prev;
		if (toe->value < head->value && head->next->value < head->value)
			command = 1;
		else if (toe->value < head->value && toe->value < head->next->value)
			command = 2;
		else
			command = 0;
		if (spec == 0)
			exec_cmd(last, command, cmd, spec);
		else
			exec_cmd(first, command, cmd, spec);
	}
}

// spec == 0 -> a, spec == 1 -> b	(descending)
// a(0) -> first = boundary, last = guard
// b(1) -> first = guard, last = boundary
// 1 = ra, rrb, 2 = rra, rb, 0 = swap
void	desecnding_less_3(t_bcl *first, t_bcl *last, t_cmd *cmd, int spec)
{
	t_bcl	*head;
	t_bcl	*toe;
	int		command;

	command = -1;
	while (!check_alignment(first, last, -1))
	{
		head = first->next;
		toe = last->prev;
		if (head->value < toe->value && head->next->value < toe->value)
			command = 2;
		else if (head->value < toe->value && head->value < head->next->value)
			command = 1;
		else
			command = 0;
		if (spec == 0)
			exec_cmd(last, command, cmd, spec);
		else
			exec_cmd(first, command, cmd, spec);
	}
}
