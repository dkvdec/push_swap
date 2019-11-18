/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:53:22 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/18 20:54:18 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		find_near(int i)
{
	int j;
	int max;

	j = 0;
	max = 0;
	i = 0;
	while (j < t_a.sz_b)
	{
		if (t_a.ar_b[j] > t_a.ar_b[max])
			max = j;
		j++;
	}
	return (max);
}

int		find_ent(int i)
{
	int j;
	int k;

	j = 0;
	while (j < t_a.sz_b)
	{
		k = j + 1;
		if (k == t_a.sz_b)
			k = 0;
		if (t_a.ar_b[j] > t_a.ar_a[i]
		&& t_a.ar_b[k] < t_a.ar_a[i])
			return (k);
		j++;
		if (j == t_a.sz_b)
		{
			k = find_near(i);
			break ;
		}
	}
	return (k);
}

int		count_price(int i, int j)
{
	int tmp;
	int sol;

	t_p.pr_a[i] = ((i > j) ? i : j) + 1;
	sol = 1;
	tmp = ((t_a.sz_a - i > t_a.sz_b - j) ? t_a.sz_a - i : t_a.sz_b - j) + 2;
	if (tmp < t_p.pr_a[i])
	{
		t_p.pr_a[i] = tmp;
		sol = 2;
	}
	tmp = i + (t_a.sz_b - j) + 2;
	if (tmp < t_p.pr_a[i])
	{
		t_p.pr_a[i] = tmp;
		sol = 3;
	}
	tmp = j + (t_a.sz_a - i) + 2;
	if (tmp < t_p.pr_a[i])
	{
		t_p.pr_a[i] = tmp;
		sol = 4;
	}
	return (sol);
}

void	count_proto(void)
{
	int i;

	i = 0;
	while (i < t_a.sz_a)
	{
		count_price(i, find_ent(i));
		i++;
	}
}

void	get_lowest(void)
{
	int i;
	int l;

	i = 0;
	t_p.sz_c = i;
	l = t_p.pr_a[i];
	while (i < t_a.sz_a)
	{
		if (l > t_p.pr_a[i])
		{
			t_p.sz_c = i;
			l = t_p.pr_a[i];
		}
		i++;
	}
}
