/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:16:12 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 16:18:08 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		get_nbrs(void)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < t_a.gc)
	{
		grep_nbrs((*t_a.gv)[i], &j);
		i++;
	}
	t_a.sz_a = t_a.sz_m;
	t_a.sz_b = 0;
	return (0);
}

void	check_n_get_argv(void)
{
	int i;

	if ((t_a.sz_m = count_nbrs()) < 0)
		return (end_error());
	if (!(t_a.ar_a = (int*)malloc(sizeof(int) * t_a.sz_m))
	|| !(t_a.ar_b = (int*)malloc(sizeof(int) * t_a.sz_m)))
		return ;
	i = -1;
	while (++i < t_a.sz_m)
	{
		t_a.ar_a[i] = 0;
		t_a.ar_b[i] = 0;
	}
	i = 0;
	get_nbrs();
}

void	check_dupl(void)
{
	int i;
	int j;

	j = 0;
	while (j < t_a.sz_m)
	{
		i = j + 1;
		while (i < t_a.sz_m)
		{
			if (t_a.ar_a[j] == t_a.ar_a[i])
				end_error();
			i++;
		}
		j++;
	}
}

void	check_sort(int flag)
{
	int i;

	i = 0;
	if (t_a.sz_b > 0)
		end_ko();
	while (i + 1 < t_a.sz_m)
	{
		if (t_a.ar_a[i] > t_a.ar_a[i + 1])
		{
			if (flag)
				return ;
			else
				end_ko();
		}
		i++;
	}
	if (flag)
		exit(0);
	else
		end_ok();
}

int		check_act(char *act)
{
	if (!(ft_strcmp(act, "sa")) ||
		!(ft_strcmp(act, "sb")) ||
		!(ft_strcmp(act, "ss")) ||
		!(ft_strcmp(act, "pa")) ||
		!(ft_strcmp(act, "pb")) ||
		!(ft_strcmp(act, "ra")) ||
		!(ft_strcmp(act, "rb")) ||
		!(ft_strcmp(act, "rr")) ||
		!(ft_strcmp(act, "rra")) ||
		!(ft_strcmp(act, "rrb")) ||
		!(ft_strcmp(act, "rrr")))
		return (0);
	return (1);
}
