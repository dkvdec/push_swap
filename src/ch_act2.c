/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_act2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:19:44 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 13:34:34 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	act_pa(int flag)
{
	if (flag)
		write(1, "pa\n", 3);
	if (t_a.sz_b > 0 && t_a.sz_a < t_a.sz_m)
	{
		push_down(0);
		t_a.sz_a++;
		t_a.ar_a[0] = t_a.ar_b[0];
		push_up(1);
		t_a.sz_b--;
	}
}

void	act_pb(int flag)
{
	if (flag)
		write(1, "pb\n", 3);
	if (t_a.sz_a > 0 && t_a.sz_b < t_a.sz_m)
	{
		push_down(1);
		t_a.sz_b++;
		t_a.ar_b[0] = t_a.ar_a[0];
		push_up(0);
		t_a.sz_a--;
	}
}

void	act_ra(int flag)
{
	int t;

	if (flag)
		write(1, "ra\n", 3);
	if (t_a.sz_a > 1)
	{
		t = t_a.ar_a[0];
		push_up(0);
		t_a.ar_a[t_a.sz_a - 1] = t;
	}
}

void	act_rb(int flag)
{
	int t;

	if (flag)
		write(1, "rb\n", 3);
	if (t_a.sz_b > 1)
	{
		t = t_a.ar_b[0];
		push_up(1);
		t_a.ar_b[t_a.sz_b - 1] = t;
	}
}

void	act_rr(int flag)
{
	if (flag)
		write(1, "rr\n", 3);
	act_ra(0);
	act_rb(0);
}
