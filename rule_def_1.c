/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_def_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:49:37 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 00:06:47 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_bcl *first, t_bcl *second)
{
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}

void	sa(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	bcl = boundary->next;
	cmd = get_cmd(cmd, 1);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (bcl->nil || bcl->next->nil)
		return ;
	swap_ab(bcl, bcl->next);
	return ;
}

void	pa(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*boundary;

	boundary = set_boundary(bcl);
	bcl = boundary;
	cmd = get_cmd(cmd, 3);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (bcl->prev->nil)
		return ;
	swap_ab(bcl->prev, bcl);
}

void	sb(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*first;
	t_bcl	*boundary;

	first = bcl;
	boundary = set_boundary(bcl);
	bcl = boundary->prev;
	cmd = get_cmd(cmd, 2);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (bcl->nil || bcl->prev->nil)
		return ;
	swap_ab(bcl->prev, bcl);
	return ;
}

void	pb(t_bcl *bcl, t_cmd *cmd)
{
	t_bcl	*boundary;

	boundary = set_boundary(bcl);
	bcl = boundary;
	cmd = get_cmd(cmd, 4);
	if (!cmd)
	{
		ft_putendl_fd("MEMORY ALLOCATE FAILURE", 2);
		free_bcl(bcl);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (bcl->next->nil)
		return ;
	swap_ab(bcl, bcl->next);
	return ;
}
