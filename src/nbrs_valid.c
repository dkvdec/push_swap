/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:43:03 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 15:53:31 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		exception_check(char *str, int i)
{
	int		j;
	char	*int_exc;

	int_exc = "2147483647";
	j = 0;
	while (j < 10)
	{
		if (j == 9 && i > 0 && str[i - 1] == '-')
		{
			if (str[i + j] > '8')
				return (1);
		}
		else if (str[i + j] > int_exc[j])
			return (1);
		j++;
	}
	return (0);
}

int		nbr_check(char *str, int *i)
{
	int j;

	j = 0;
	while (str[(*i) + j] && str[(*i) + j] >= 48 && str[(*i) + j] <= 57)
		j++;
	if (j > 9)
		if (j > 10 || exception_check(str, (*i)))
			return (1);
	(*i) += j;
	return (0);
}

int		line_pass(char *str)
{
	int i;
	int nb_c;

	i = 0;
	nb_c = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57)
		|| (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57)))
		{
			if (i > 0 && (str[i - 1] != ' ' && str[i] != ','))
				end_error();
			nb_c++;
			i += ((str[i] == '-') ? 1 : 0);
			if (nbr_check(str, &i))
				return (-1);
		}
		else if (str[i] == ' ' || str[i] == ',')
			i++;
		else
			return (-1);
	}
	return (nb_c);
}

int		count_nbrs(void)
{
	int i;
	int tmp;
	int nb_c;

	i = 1;
	nb_c = 0;
	while (i < t_a.gc)
	{
		tmp = line_pass((*t_a.gv)[i]);
		if (tmp < 0)
			return (-1);
		else
			nb_c += tmp;
		i++;
	}
	return (nb_c);
}

int		grep_nbrs(char *str, int *j)
{
	int i;

	i = 0;
	while (str[i] && ((*j) < t_a.sz_m))
	{
		if ((str[i] >= 48 && str[i] <= 57)
		|| (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57)))
		{
			t_a.ar_a[(*j)++] = ft_atoi(str + i);
			i += ((str[i] == '-') ? 1 : 0);
			while (str[i] && str[i] >= 48 && str[i] <= 57)
				i++;
		}
		else
			i++;
	}
	return (0);
}
