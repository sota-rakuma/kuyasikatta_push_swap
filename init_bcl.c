/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bcl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:16:11 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/04 23:51:34 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bcl	*get_bcl(char *argv[], int argc, t_bcl *guard, t_bcl *boundary)
{
	t_bcl	*bcl;
	int		i;

	guard->nil = 1;
	boundary->nil = 1;
	guard->next = boundary;
	boundary->prev = guard;
	bcl = boundary;
	i = 0;
	while (++i < argc)
	{
		bcl->next = ft_lstnew(ft_atoi(argv[i]));
		if (bcl->next == NULL)
		{
			ft_lstclear(&bcl, NULL);
			return (NULL);
		}
		bcl->next->prev = bcl;
		bcl = bcl->next;
	}
	return (bcl);
}

t_bcl	*init_bcl(int argc, char *argv[])
{
	t_bcl	*bcl;
	t_bcl	*guard;
	t_bcl	*boundary;

	guard = ft_lstnew(0);
	boundary = ft_lstnew(0);
	if (!guard || !boundary)
		return (NULL);
	bcl = get_bcl(argv, argc, guard, boundary);
	if (!bcl)
		return (NULL);
	bcl->next = guard;
	guard->prev = bcl;
	return (guard);
}

t_cmd	*ft_cmdnew(int content)
{
	t_cmd	*lst;

	lst = (t_cmd *)malloc(sizeof(t_cmd));
	if (lst == NULL)
		return (NULL);
	lst->cmd = content;
	lst->nil = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*first;

	first = ft_cmdnew(0);
	if (!first)
		return (NULL);
	first->nil = 1;
	first->next = first;
	first->prev = first;
	return (first);
}

/*
SA = 1
SB = 2
PA = 3
PB = 4
RA = 5
RB = 6
RRA = 7
RRB = 8
SS = 9
RR = 10
RRR = 11
*/
t_cmd	*get_cmd(t_cmd *first, int cmd)
{
	t_cmd	*new;
	t_cmd	*last;

	new = ft_cmdnew(cmd);
	last = first->prev;
	if (!new)
	{
		free_cmd(first);
		return (NULL);
	}
	last->next = new;
	new->prev = last;
	first->prev = new;
	new->next = first;
	return (first);
}
