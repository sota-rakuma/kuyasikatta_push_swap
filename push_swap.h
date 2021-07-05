/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:54:33 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 18:14:50 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

//# define MALLOCFAIL 0

typedef struct s_cmd
{
	int				cmd;
	int				nil;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}			t_cmd;

t_bcl	*init_bcl(int argc, char *argv[]);
t_cmd	*init_cmd(void);
t_cmd	*get_cmd(t_cmd *first, int cmd);
void	ft_swap(void *a, void *b);
t_bcl	*set_boundary(t_bcl *bcl);
t_bcl	*set_last(t_bcl *start, int cnt);
t_cmd	*ft_cmdnew(int content);
int		check_dupulication(t_bcl *bcl);
void	check_arg_range(int argc, char *argv[]);
void	organaise_cmd(t_cmd *first);
t_cmd	*translate_cmds(t_cmd *lst, int spec);
void	print_cmd(t_cmd *cmd);
void	print_cmd_all(t_cmd *first);
void	free_dp(char **arr);
void	free_cmd(t_cmd *first);
void	free_bcl(t_bcl *first);
void	swap_ab(t_bcl *first, t_bcl *second);
void	rotate_ab(t_bcl *target, t_bcl *left, t_bcl *right);
void	pa(t_bcl *bcl, t_cmd *cmd);
void	pb(t_bcl *bcl, t_cmd *cmd);
void	sa(t_bcl *bcl, t_cmd *cmd);
void	sb(t_bcl *bcl, t_cmd *cmd);
void	ra(t_bcl *bcl, t_cmd *cmd);
void	rra(t_bcl *bcl, t_cmd *cmd);
void	rb(t_bcl *bcl, t_cmd *cmd);
void	rrb(t_bcl *bcl, t_cmd *cmd);
void	ss(t_bcl *bcl, t_cmd *cmd);
void	rr(t_bcl *bcl, t_cmd *cmd);
void	rrr(t_bcl *bcl, t_cmd *cmd);
int		check_alignment(t_bcl *first, t_bcl *last, int specifier);
t_bcl	*find_next_min(t_bcl *first, t_bcl *last, long min);
t_bcl	*calc_median(t_bcl *first, t_bcl *last);
t_bcl	*find_max(t_bcl *first, t_bcl *last);
t_bcl	*find_min(t_bcl *first, t_bcl *last);
void	asecnding_less_3(t_bcl *first, t_bcl *last, t_cmd *cmd, int spec);
void	desecnding_less_3(t_bcl *first, t_bcl *last, t_cmd *cmd, int spec);
void	align_less_6(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd);
t_bcl	*calc_median(t_bcl *bcl, t_bcl *last);
int		proc_remains_less_5(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd, int num);
void	pop_back(t_bcl *bcl, t_bcl *boundary, t_cmd *cmd, int num);
void	proc_remains_less_1(t_bcl *bcl, t_cmd *cmd, int size);
void	quick_sort(t_bcl *first, t_bcl *last, t_cmd *cmd);
void	align_more_7(t_bcl *bcl, t_cmd *cmd);

void	for_test(t_bcl *bcl);//for test

#endif