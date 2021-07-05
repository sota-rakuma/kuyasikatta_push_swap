/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 01:14:23 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:16:55 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_cmd *first)
{
	t_cmd	*head;

	head = first->prev;
	if (head->cmd == 1)
		ft_putendl_fd("sa", 1);
	else if (head->cmd == 2)
		ft_putendl_fd("sb", 1);
	else if (head->cmd == 3)
		ft_putendl_fd("pa", 1);
	else if (head->cmd == 4)
		ft_putendl_fd("pb", 1);
	else if (head->cmd == 5)
		ft_putendl_fd("ra", 1);
	else if (head->cmd == 6)
		ft_putendl_fd("rb", 1);
	else if (head->cmd == 7)
		ft_putendl_fd("rra", 1);
	else if (head->cmd == 8)
		ft_putendl_fd("rrb", 1);
	else if (head->cmd == 9)
		ft_putendl_fd("ss", 1);
	else if (head->cmd == 10)
		ft_putendl_fd("rr", 1);
	else if (head->cmd == 11)
		ft_putendl_fd("rrr", 1);
}

void	print_cmd_all(t_cmd *first)
{
	t_cmd	*cmd;
	t_cmd	*last;

	organaise_cmd(first);
	last = first->next;
	cmd = last->next;
	while (cmd != last)
	{
		print_cmd(cmd);
		cmd = cmd->next;
	}
}
