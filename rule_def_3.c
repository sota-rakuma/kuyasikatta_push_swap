/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_def_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:34:26 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 00:07:19 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_bcl *bcl, t_cmd *cmd)
{
	sa(bcl, cmd);
	sb(bcl, cmd);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	translate_cmds(cmd->prev->prev, 1);
}

void	rr(t_bcl *bcl, t_cmd *cmd)
{
	ra(bcl, cmd);
	rb(bcl, cmd);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	translate_cmds(cmd->prev->prev, 2);
}

void	rrr(t_bcl *bcl, t_cmd *cmd)
{
	rra(bcl, cmd);
	rrb(bcl, cmd);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	translate_cmds(cmd->prev->prev, 3);
}
