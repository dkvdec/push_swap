/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:36:56 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 16:33:54 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ext_rotate(void)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i < t_a.sz_b)
	{
		if (t_a.ar_b[i] > t_a.ar_b[max])
			max = i;
		i++;
	}
	if (max < t_a.sz_b - max)
		while (max-- > 0)
			act_rb(1);
	else
		while (max++ < t_a.sz_b)
			act_rrb(1);
}

void	sort_proto(void)
{
	t_p.sz_m = t_a.sz_a;
	t_p.pr_a = (int *)malloc(sizeof(int) * t_p.sz_m);
	while (t_a.sz_a > 3)
	{
		count_proto();
		get_lowest();
		do_actions();
	}
	ext_rotate();
}

void	collector(void)
{
	int i;

	i = 3;
	while (t_a.sz_b > 0)
	{
		if (t_a.ar_b[0] < t_a.ar_a[t_a.sz_a - 1] && i > 0)
		{
			act_rra(1);
			i--;
		}
		else
			act_pa(1);
	}
	if (i > 0)
		while (i > 0)
		{
			act_rra(1);
			i--;
		}
}

void	sort_core(void)
{
	while (t_a.sz_a > 3 && t_a.sz_b < 3)
	{
		act_pb(1);
	}
	if (t_a.sz_b == 3)
		sort_stack(1);
	else if (t_a.sz_b == 2)
		sort_micro(1);
	if (t_a.sz_a > 3)
		sort_proto();
	if (t_a.sz_a == 3)
		sort_stack(0);
	else if (t_a.sz_a == 2)
		sort_micro(0);
	if (t_a.sz_b > 0)
		collector();
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_a.gc = argc;
		t_a.gv = &argv;
		t_a.sz_m = 0;
		check_n_get_argv(0);
		check_dupl();
		check_sort(1);
		sort_core();
	}
	exit(0);
}
