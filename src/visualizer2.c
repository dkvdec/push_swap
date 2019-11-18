/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:42:50 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/18 20:43:45 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	show_head(void)
{
	if (t_v.h)
	{
		ft_printf("{y+}______________________________________\n");
		ft_printf("|              | {g+}total{y+}|              |\n");
		ft_printf("|       {g+}A{y+}      |{r+}%6d{y+}|", t_v.c);
		ft_printf("      {g+}B{y+}       |\n");
		ft_printf("|______________|______|______________|{w-}\n");
	}
	else
	{
		ft_printf("{y+}_________________    _________________\n");
		ft_printf("|               |    |               |\n");
		ft_printf("|       {g+}A{y+}       |    |       {g+}B{y+}       |\n");
		ft_printf("|_______________|    |_______________|{w-}\n");
	}
}

void	get_symbols3(char ***ca, char ***cb, char *com)
{
	if (!(ft_strcmp(com, "RRA")))
	{
		***ca = 'v';
		***cb = ' ';
	}
	else if (!(ft_strcmp(com, "RRB")))
	{
		***ca = ' ';
		***cb = 'v';
	}
	else if (!(ft_strcmp(com, "RRR")))
	{
		***ca = 'v';
		***cb = 'v';
	}
	else
	{
		***ca = ' ';
		***cb = ' ';
	}
}

void	get_symbols2(char **ca, char **cb, char *com)
{
	if (!(ft_strcmp(com, "PA")))
	{
		**ca = '<';
		**cb = '<';
	}
	else if (!(ft_strcmp(com, "RA")))
	{
		**ca = '^';
		**cb = ' ';
	}
	else if (!(ft_strcmp(com, "RB")))
	{
		**ca = ' ';
		**cb = '^';
	}
	else if (!(ft_strcmp(com, "RR")))
	{
		**ca = '^';
		**cb = '^';
	}
	else
		get_symbols3(&ca, &cb, com);
}

void	get_symbols(char *ca, char *cb, char *com)
{
	if (!(ft_strcmp(com, "SA")))
	{
		*ca = 's';
		*cb = ' ';
	}
	else if (!(ft_strcmp(com, "SB")))
	{
		*ca = ' ';
		*cb = 's';
	}
	else if (!(ft_strcmp(com, "SS")))
	{
		*ca = 's';
		*cb = 's';
	}
	else if (!(ft_strcmp(com, "PB")))
	{
		*ca = '>';
		*cb = '>';
	}
	else
		get_symbols2(&ca, &cb, com);
}

void	show_bot(char *com)
{
	char ca;
	char cb;

	if (t_v.b)
	{
		get_symbols(&ca, &cb, com);
		ft_printf("{y+}______________________________________\n");
		ft_printf("|            | {g+}current{y+}  |            |\n");
		ft_printf("|  {g+}%1$c %1$c %1$c %1$c %1$c{y+} |  {g+}action", ca);
		ft_printf("{y+}  | {g+}%1$c %1$c %1$c %1$c %1$c{y+}  |\n", cb);
		ft_printf("|____________|___{r+}%3s{y+} ___|____________|{w-}\n", com);
	}
}
