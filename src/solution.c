/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:50:19 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 16:51:04 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sol_tt(int i, int j)
{
	while (i > 0 || j > 0)
	{
		if (i > 0 && j > 0)
		{
			act_rr(1);
			i--;
			j--;
		}
		else if (i > 0)
		{
			act_ra(1);
			i--;
		}
		else if (j > 0)
		{
			act_rb(1);
			j--;
		}
	}
	act_pb(1);
}

void	sol_bb(int i, int j)
{
	while (i + 1 < t_a.sz_a || j + 1 < t_a.sz_b)
	{
		if (i + 1 < t_a.sz_a && j + 1 < t_a.sz_b)
		{
			act_rrr(1);
			i++;
			j++;
		}
		else if (i + 1 < t_a.sz_a)
		{
			act_rra(1);
			i++;
		}
		else if (j + 1 < t_a.sz_b)
		{
			act_rrb(1);
			j++;
		}
	}
	act_rrr(1);
	act_pb(1);
}

void	sol_tb(int i, int j)
{
	while (i > 0 || j + 1 < t_a.sz_b)
	{
		if (i > 0)
		{
			act_ra(1);
			i--;
		}
		if (j + 1 < t_a.sz_b)
		{
			act_rrb(1);
			j++;
		}
	}
	act_rrb(1);
	act_pb(1);
}

void	sol_bt(int i, int j)
{
	while (i + 1 < t_a.sz_a || j > 0)
	{
		if (i + 1 < t_a.sz_a)
		{
			act_rra(1);
			i++;
		}
		if (j > 0)
		{
			act_rb(1);
			j--;
		}
	}
	act_rra(1);
	act_pb(1);
}

void	do_actions(void)
{
	int j;
	int sol;

	j = find_ent(t_p.sz_c);
	sol = count_price(t_p.sz_c, j);
	if (sol == 1)
		sol_tt(t_p.sz_c, j);
	else if (sol == 2)
		sol_bb(t_p.sz_c, j);
	else if (sol == 3)
		sol_tb(t_p.sz_c, j);
	else if (sol == 4)
		sol_bt(t_p.sz_c, j);
}
