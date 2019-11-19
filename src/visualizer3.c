/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:43:15 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 21:27:14 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	show_body(int i)
{
	i = 0;
	while (i < t_a.sz_a && i < t_a.sz_b)
	{
		ft_printf("%11d%10c%11d\n", t_a.ar_a[i], ' ', t_a.ar_b[i]);
		i++;
	}
	while (i < t_a.sz_b)
		ft_printf("%11c%10c%11d\n", ' ', ' ', t_a.ar_b[i++]);
	while (i < t_a.sz_a)
		ft_printf("%11d%10c%11c\n", t_a.ar_a[i++], ' ', ' ');
	while (i <= t_a.sz_m && i++)
		write(1, "\n", 1);
}

void	get_mark2(void)
{
	if (!(ft_strcmp(t_v.c_c, "RR")))
	{
		if (t_a.sz_a > 1)
			t_v.ai = t_a.sz_a - 1;
		if (t_a.sz_b > 1)
			t_v.bi = t_a.sz_b - 1;
	}
	else if (!(ft_strcmp(t_v.c_c, "SA")) && t_a.sz_a > 1
	&& (t_v.aai = 1))
		t_v.ai = 0;
	else if (!(ft_strcmp(t_v.c_c, "SB")) && t_a.sz_b > 1
	&& (t_v.bbi = 1))
		t_v.bi = 0;
	else if (!(ft_strcmp(t_v.c_c, "SS")))
	{
		if (t_a.sz_a > 1 && !(t_v.ai = 0))
			t_v.aai = 1;
		if (t_a.sz_b > 1 && !(t_v.bi = 0))
			t_v.bbi = 1;
	}
}

void	get_mark(void)
{
	t_v.ai = -1;
	t_v.aai = -1;
	t_v.bi = -1;
	t_v.bbi = -1;
	if (!(ft_strcmp(t_v.c_c, "PA")
	|| (!(ft_strcmp(t_v.c_c, "RRA")) && t_a.sz_a > 1)))
		t_v.ai = 0;
	else if ((!(ft_strcmp(t_v.c_c, "PB"))
	|| (!(ft_strcmp(t_v.c_c, "RRB")) && t_a.sz_b > 1)))
		t_v.bi = 0;
	else if (!(ft_strcmp(t_v.c_c, "RRR")))
	{
		if (t_a.sz_a > 1)
			t_v.ai = 0;
		if (t_a.sz_b > 1)
			t_v.bi = 0;
	}
	else if (!(ft_strcmp(t_v.c_c, "RA")) && t_a.sz_a > 1)
		t_v.ai = t_a.sz_a - 1;
	else if (!(ft_strcmp(t_v.c_c, "RB")) && t_a.sz_b > 1)
		t_v.bi = t_a.sz_b - 1;
	else
		get_mark2();
}

void	show_body_ext2(int i)
{
	while (i < t_a.sz_b)
		if (i == t_v.bi || i == t_v.bbi)
			ft_printf("%11c%10c{r+}%11d{w-}\n", ' ', ' ', t_a.ar_b[i++]);
		else
			ft_printf("%11c%10c%11d\n", ' ', ' ', t_a.ar_b[i++]);
	while (i < t_a.sz_a)
		if (i == t_v.ai || i == t_v.aai)
			ft_printf("{r+}%11d{w-}%10c%11c\n", t_a.ar_a[i++], ' ', ' ');
		else
			ft_printf("%11d%10c%11c\n", t_a.ar_a[i++], ' ', ' ');
	while (i <= t_a.sz_m && i++)
		ft_printf("\n");
}

void	show_body_ext(int i)
{
	get_mark();
	i = 0;
	while (i < t_a.sz_a && i < t_a.sz_b)
	{
		if (i == t_v.ai || i == t_v.aai)
			ft_printf("{r+}%11d{w-}%10c", t_a.ar_a[i], ' ');
		else
			ft_printf("%11d%10c", t_a.ar_a[i], ' ');
		if (i == t_v.bi || i == t_v.bbi)
			ft_printf("{r+}%11d{w-}\n", t_a.ar_b[i]);
		else
			ft_printf("%11d\n", t_a.ar_b[i]);
		i++;
	}
	show_body_ext2(i);
}
