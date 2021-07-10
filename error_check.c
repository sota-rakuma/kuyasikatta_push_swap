/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:58:54 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/10 21:19:39 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dupulication(t_bcl *bcl)
{
	t_bcl	*start;
	t_bcl	*head;

	start = set_boundary(bcl);
	start = start->next;
	while (start != bcl)
	{
		head = start->next;
		while (head != bcl)
		{
			if (start->value == head->value)
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			head = head->next;
		}
		start = start->next;
	}
	return (1);
}

int	ft_isnum(char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv) && *argv != '-')
			return (0);
		argv++;
	}
	return (1);
}

static int	is_ok(int num, int c, int flag)
{
	int	ov_div;
	int	ov_mod;
	int	nxt;

	nxt = c - '0';
	num *= flag;
	if (num >= 0)
	{
		ov_div = INT_MAX / 10;
		ov_mod = INT_MAX % 10;
		if ((ov_div < num) || (ov_div == num && ov_mod < nxt))
			return (0);
	}
	else
	{
		ov_div = INT_MIN / 10;
		ov_mod = INT_MIN % 10 * (-1);
		if ((ov_div > num) || (ov_div == num && ov_mod < nxt))
			return (0);
	}
	return (1);
}

int	is_numrange_ok(char *argv)
{
	int	num;
	int	flag;

	flag = 1;
	if (*argv == '-')
	{
		flag = -1;
		argv++;
	}
	num = 0;
	while (*argv)
	{
		if (!is_ok(num, *argv, flag))
			return (0);
		num = ((num * 10) + (*argv - '0'));
		argv++;
	}
	return (1);
}

void	check_arg_range(int argc, char *argv[])
{
	argv++;
	while (--argc > 0)
	{
		if (!ft_isnum(*argv))
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		if (!is_numrange_ok(*argv))
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		argv++;
	}
}
