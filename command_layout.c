/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 01:35:20 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:35:51 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//spec = 1->ss, 2->rr, 3->rrr
t_cmd	*translate_cmds(t_cmd *lst, int spec)
{
	t_cmd	*tmp;

	if (spec == 1)
		lst->next->cmd = 9;
	else if (spec == 2)
		lst->next->cmd = 10;
	else
		lst->next->cmd = 11;
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	tmp = lst->next;
	free(lst);
	return (tmp->prev);
}

t_cmd	*del_cmds(t_cmd *lst)
{
	t_cmd	*start;
	t_cmd	*end;
	t_cmd	*tmp;

	start = lst;
	tmp = lst->next;
	end = lst->next->next;
	start->next = end->next;
	end->next->prev = start;
	free(end);
	free(tmp);
	return (lst->prev);
}

int	no_move(t_cmd *head)
{
	if ((head->cmd == 3 && head->next->cmd == 4)
		|| (head->cmd == 4 && head->next->cmd == 3)
		|| (head->cmd == 5 && head->next->cmd == 7)
		|| (head->cmd == 7 && head->next->cmd == 5)
		|| (head->cmd == 6 && head->next->cmd == 8)
		|| (head->cmd == 8 && head->next->cmd == 6)
		|| (head->cmd == 10 && head->next->cmd == 11)
		|| (head->cmd == 11 && head->next->cmd == 10))
		return (1);
	else
		return (0);
}

void	organaise_cmd(t_cmd *first)
{
	t_cmd	*head;

	head = first->next;
	while (head->next != first)
	{
		if ((head->cmd == 1 && head->next->cmd == 2)
			|| (head->cmd == 2 && head->next->cmd == 1))
			head = translate_cmds(head, 1);
		else if ((head->cmd == 5 && head->next->cmd == 6)
			|| (head->cmd == 6 && head->next->cmd == 5))
			head = translate_cmds(head, 2);
		else if ((head->cmd == 7 && head->next->cmd == 8)
			|| (head->cmd == 8 && head->next->cmd == 7))
			head = translate_cmds(head, 3);
		else if (no_move(head))
			head = del_cmds(head->prev);
		head = head->next;
	}
}
