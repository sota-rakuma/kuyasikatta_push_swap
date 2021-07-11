/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 01:12:52 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/11 13:54:15 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dp(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_cmd(t_cmd *first)
{
	t_cmd	*last;
	t_cmd	*tmp;

	last = first;
	tmp = first->next;
	first = tmp->next;
	while (first != last)
	{
		free(tmp);
		tmp = first;
		first = first->next;
	}
	if (last->prev != last)
		free(last->prev);
	free(last);
}

void	free_bcl(t_bcl *first)
{
	t_bcl	*last;
	t_bcl	*tmp;

	last = first;
	tmp = first->next;
	first = tmp->next;
	while (first != last)
	{
		free(tmp);
		tmp = first;
		first = first->next;
	}
	free(last->prev);
	free(last);
}
