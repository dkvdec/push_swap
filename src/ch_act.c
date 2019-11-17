/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:19:38 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/14 20:59:46 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	act_sa(int flag)
{
	int t;

	if (flag)
		write(1, "sa\n", 3);
	if (t_a.sz_a > 1)
	{
		t = t_a.ar_a[0];
		t_a.ar_a[0] = t_a.ar_a[1];
		t_a.ar_a[1] = t;
	}
}

void	act_sb(int flag)
{
	int t;

	if (flag)
		write(1, "sb\n", 3);
	if (t_a.sz_b > 1)
	{
		t = t_a.ar_b[0];
		t_a.ar_b[0] = t_a.ar_b[1];
		t_a.ar_b[1] = t;
	}
}

void	act_ss(int flag)
{
	if (flag)
		write(1, "ss\n", 3);
	act_sa(0);
	act_sb(0);
}

void	push_up(int flag)
{
	int i;
	int max;
	int *stack;

	if (flag)
	{
		max = t_a.sz_b - 1;
		stack = t_a.ar_b;
	}
	else
	{
		max = t_a.sz_a - 1;
		stack = t_a.ar_a;
	}
	i = 0;
	while (i < max)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	push_down(int flag)
{
	int i;
	int *stack;

	if (flag)
	{
		i = ((t_a.sz_b < t_a.sz_m) ? t_a.sz_b : t_a.sz_m - 1);
		stack = t_a.ar_b;
	}
	else
	{
		i = ((t_a.sz_a < t_a.sz_m) ? t_a.sz_a : t_a.sz_m - 1);
		stack = t_a.ar_a;
	}
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}
