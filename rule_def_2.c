/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_def_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:41:47 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 00:08:11 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_bcl *target, t_bcl *left, t_bcl *right)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;
	left->next = target;
	right->prev = target;
	target->prev = left;
	target->next = right;
}

void	ra(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	cmd = get_cmd(cmd, 5);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (boundary->next->nil)
		return ;
	rotate_ab(boundary->next, first->prev, first);
	return ;
}

void	rra(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	cmd = get_cmd(cmd, 7);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (boundary->next->nil)
		return ;
	rotate_ab(first->prev, boundary, boundary->next);
	return ;
}

void	rb(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	cmd = get_cmd(cmd, 6);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (boundary->prev->nil)
		return ;
	rotate_ab(boundary->prev, first, first->next);
	return ;
}

void	rrb(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	cmd = get_cmd(cmd, 8);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (boundary->prev->nil)
		return ;
	rotate_ab(first->next, boundary->prev, boundary);
	return ;
}
