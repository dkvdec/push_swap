/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_act3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:28:28 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/18 21:43:05 by dheredat         ###   ########.fr       */
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
		show_stacks_core("SA", act_sa, 0);
	else if (!(ft_strcmp(act, "sb")))
		show_stacks_core("SB", act_sb, 0);
	else if (!(ft_strcmp(act, "ss")))
		show_stacks_core("SS", act_ss, 0);
	else if (!(ft_strcmp(act, "pa")))
		show_stacks_core("PA", act_pa, 0);
	else if (!(ft_strcmp(act, "pb")))
		show_stacks_core("PB", act_pb, 0);
	else if (!(ft_strcmp(act, "ra")))
		show_stacks_core("RA", act_ra, 0);
	else if (!(ft_strcmp(act, "rb")))
		show_stacks_core("RB", act_rb, 0);
	else if (!(ft_strcmp(act, "rr")))
		show_stacks_core("RR", act_rr, 0);
	else if (!(ft_strcmp(act, "rra")))
		show_stacks_core("RRA", act_rra, 0);
	else if (!(ft_strcmp(act, "rrb")))
		show_stacks_core("RRB", act_rrb, 0);
	else if (!(ft_strcmp(act, "rrr")))
		show_stacks_core("RRR", act_rrr, 0);
}

void	spin_act(char **act)
{
	int i;

	if (t_v.v)
		show_stacks("ORG");
	i = 0;
	while (act[i])
	{
		t_v.c = i + 1;
		exec_act(act[i++]);
	}
	i = 0;
	while (act[i])
	{
		free(act[i]);
		i++;
	}
	free(act);
	if (t_v.v)
		show_stacks("FNL");
}
