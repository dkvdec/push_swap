/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:51:59 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/18 17:43:13 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_act(int act, int flag)
{
	if (act == 1)
		(flag) ? act_sb(1) : act_rra(1);
	else if (act == 2)
		(flag) ? act_rrb(1) : act_sa(1);
	else if (act == 3)
	{
		(flag) ? 0 : act_sa(1);
		(flag) ? 0 : act_rra(1);
	}
	else if (act == 4)
	{
		(flag) ? act_sb(1) : 0;
		(flag) ? act_rrb(1) : 0;
	}
	else if (act == 5)
	{
		(flag) ? act_rb(1) : act_sa(1);
		(flag) ? 0 : act_ra(1);
	}
	else if (act == 6)
	{
		(flag) ? act_sb(1) : act_ra(1);
		(flag) ? act_rb(1) : 0;
	}
}

void	sort_stack(int flag)
{
	int *stack;

	if (flag)
		stack = t_a.ar_b;
	else
		stack = t_a.ar_a;
	if (stack[0] < stack[1] && stack[0] > stack[2])
		sort_act(1, flag);
	else if (stack[0] < stack[2] && stack[0] > stack[1])
		sort_act(2, flag);
	else if (stack[1] < stack[0] && stack[1] > stack[2])
		sort_act(3, flag);
	else if (stack[1] < stack[2] && stack[1] > stack[0])
		sort_act(4, flag);
	else if (stack[2] < stack[1] && stack[2] > stack[0])
		sort_act(5, flag);
	else if (stack[2] < stack[0] && stack[2] > stack[1])
		sort_act(6, flag);
}

void	sort_micro(int flag)
{
	if (flag && t_a.ar_b[1] > t_a.ar_b[0])
		act_sb(1);
	else if (t_a.ar_a[0] > t_a.ar_a[1])
		act_sa(1);
}
