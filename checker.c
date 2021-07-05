/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:57:06 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 22:53:27 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

char	**get_cmd_arr(void)
{
	char	*tmp;
	char	**arr;

	tmp = ft_strdup("pa pb ra rb rra rrb sa sb rr rrr ss");
	if (!tmp)
	{
		ft_putendl_fd("mmemory allocate Error", 2);
		exit(EXIT_FAILURE);
	}
	arr = ft_split(tmp, ' ');
	free(tmp);
	if (!arr)
	{
		ft_putendl_fd("mmemory allocate Error", 2);
		exit(EXIT_FAILURE);
	}
	return (arr);
}

int	cmp_cmd(char **arr, char *line)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(arr[i], line, ft_strlen(arr[i]) + 1))
		{
			free_dp(arr);
			return (i);
		}
	}
	free_dp(arr);
	return (-1);
}

int	execute_cmd(int command, t_bcl *bcl, t_cmd *cmd)
{
	void	(*cmds[11])(t_bcl *, t_cmd *);

	if (command == -1)
		return (0);
	cmds[0] = pa;
	cmds[1] = pb;
	cmds[2] = ra;
	cmds[3] = rb;
	cmds[4] = rra;
	cmds[5] = rrb;
	cmds[6] = sa;
	cmds[7] = sb;
	cmds[8] = rr;
	cmds[9] = rrr;
	cmds[10] = ss;
	(*cmds[command])(bcl, cmd);
	return (1);
}

int	read_cmds(t_bcl *bcl, t_cmd *cmd)
{
	char	*line;
	int		res;

	res = get_next_line(0, &line);
	while (-1 != res)
	{
		if (res == 1 && !execute_cmd(cmp_cmd(get_cmd_arr(), line), bcl, cmd))
		{
			free(line);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (res == 0)
		{
			free(line);
			if (!check_alignment(set_boundary(bcl), bcl, 0) || !bcl->next->nil)
			{
				ft_putendl_fd("KO", 2);
				return (0);
			}
			return (1);
		}
		res = get_next_line(0, &line);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	int		flag;
	t_bcl	*bcl;
	t_cmd	*cmd;

	if (argc <= 1)
		return (0);
	check_arg_range(argc, argv);
	flag = 1;
	bcl = init_bcl(argc, argv);
	if (!check_dupulication(bcl))
	{
		free(bcl);
		exit(EXIT_FAILURE);
	}
	cmd = init_cmd();
	flag = read_cmds(bcl, cmd);
	if (flag == -1)
		ft_putendl_fd("Read Error", 2);
	free_bcl(bcl);
	free_cmd(cmd);
	if (!flag || flag == -1)
		exit(EXIT_FAILURE);
	ft_putendl_fd("OK", 1);
	exit(EXIT_SUCCESS);
}
