/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:30:01 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 20:14:06 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	show_stacks(char *com)
{
	int i;

	i = 100;
	while (i-- > 1)
		write(1, "\n", 1);
	show_head();
	if (t_v.l && ft_strcmp("  ", com))
	{
		t_v.c_c = com;
		show_body_ext(i);
	}
	else
		show_body(i);
	i = 0;
	show_bot(com);
	while (i < t_v.t)
		i++;
}

void	show_stacks_core(char *com, void (*f)(int), int flag)
{
	if (t_v.v && t_v.b)
		show_stacks("  ");
	(*f)(flag);
	if (t_v.v)
		show_stacks(com);
}

void	reset_options(void)
{
	t_v.v = 0;
	t_v.t = 0;
	t_v.h = 0;
	t_v.b = 0;
	t_v.l = 0;
	t_v.c = 0;
}

int		wait_options(char *str, int i)
{
	int j;

	j = 0;
	t_v.t = 60000000;
	if (ft_isdigit(str[i + j]))
	{
		while (str[i + j] && ft_isdigit(str[i + j]))
			j++;
		if (j > 10 || (j == 10 && exception_check(str, i)))
			end_error();
		t_v.t = ft_atoi(str + i);
		i += j;
	}
	return (i);
}

int		check_options(char *str, int i)
{
	if (str[0] == '-' && (i = 1))
	{
		if (str[i] && ft_isdigit(str[i]))
			return (0);
		while (str[i])
		{
			if (str[i] == 'v' && i++)
				t_v.v = 1;
			else if (str[i] == 't' && i++)
				i = wait_options(str, i);
			else if (str[i] == 'h' && i++)
				t_v.h = 1;
			else if (str[i] == 'b' && i++)
				t_v.b = 1;
			else if (str[i] == 'l' && i++)
				t_v.l = 1;
			else
				end_error();
		}
		if (t_a.gc == 2)
			end_error();
	}
	else
		return (0);
	return (1);
}
