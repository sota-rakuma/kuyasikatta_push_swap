/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:53:37 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 22:51:01 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_sort(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd, int len)
{
	if (len < 4)
		asecnding_less_3(boundary, bcl, cmd, 0);
	else if (len < 7)
		align_less_6(bcl, boundary, cmd);
	else
		align_more_7(bcl, cmd);
	print_cmd_all(cmd);
}

int	main(int argc, char *argv[])
{
	t_bcl	*bcl;
	t_bcl	*boundary;
	t_cmd	*cmd;

	check_arg_range(argc, argv);
	bcl = init_bcl(argc, argv);
	if (!bcl)
	{
		ft_putendl_fd("memory allocate failure", 2);
		exit (EXIT_FAILURE);
	}
	cmd = init_cmd();
	if (!cmd)
	{
		ft_putendl_fd("memory allocate failure", 2);
		free_bcl(bcl);
		exit (EXIT_FAILURE);
	}
	boundary = set_boundary(bcl);
	if (check_dupulication(bcl))
		exec_sort(bcl, boundary, cmd, ft_lstsize(boundary, bcl));
	free_bcl(bcl);
	free_cmd(cmd);
	return (0);
}
