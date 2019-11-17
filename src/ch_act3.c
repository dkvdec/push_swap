/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_act3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:28:28 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/14 21:05:18 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	act_rra(int flag)
{
	int t;

	if (flag)
		write(1, "rra\n", 4);
	if (t_a.sz_a > 1)
	{
		t = t_a.ar_a[t_a.sz_a - 1];
		push_down(0);
		t_a.ar_a[0] = t;
	}
}

void	act_rrb(int flag)
{
	int t;

	if (flag)
		write(1, "rrb\n", 4);
	if (t_a.sz_b > 1)
	{
		t = t_a.ar_b[t_a.sz_b - 1];
		push_down(1);
		t_a.ar_b[0] = t;
	}
}

void	act_rrr(int flag)
{
	if (flag)
		write(1, "rrr\n", 4);
	act_rra(0);
	act_rrb(0);
}

void	exec_act(char *act)
{
	if (!(ft_strcmp(act, "sa")))
		act_sa(0);
	else if (!(ft_strcmp(act, "sb")))
		act_sb(0);
	else if (!(ft_strcmp(act, "ss")))
		act_ss(0);
	else if (!(ft_strcmp(act, "pa")))
		act_pa(0);
	else if (!(ft_strcmp(act, "pb")))
		act_pb(0);
	else if (!(ft_strcmp(act, "ra")))
		act_ra(0);
	else if (!(ft_strcmp(act, "rb")))
		act_rb(0);
	else if (!(ft_strcmp(act, "rr")))
		act_rr(0);
	else if (!(ft_strcmp(act, "rra")))
		act_rra(0);
	else if (!(ft_strcmp(act, "rrb")))
		act_rrb(0);
	else if (!(ft_strcmp(act, "rrr")))
		act_rrr(0);
}

void	spin_act(char **act)
{
	int i;

	i = 0;
	while (act[i])
		exec_act(act[i++]);
}
