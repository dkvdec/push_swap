/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:08:49 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 16:21:20 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.		>>> 1
**		Do nothing if there is only one or no elements).
** sb : swap b - swap the first 2 elements at the top of stack b.		>>> 2
**		Do nothing if there	is only one or no elements).
** ss : sa and sb at the same time.										>>> 3
** pa : push a - take the first element at the top of b and put			>>> 4
**		it at the top of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put			>>> 5
**		it at the top of b. Do nothing if a is empty.
** ra : rotate a - shift up all elements of stack a by 1.				>>> 6
**		The first element becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1.				>>> 7
**		The first element becomes the last one.
** rr : ra and rb at the same time.										>>> 8
** rra : reverse rotate a - shift down all elements of stack a by 1.	>>> 4
**		The last element becomes the first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1.	>>> 5
**		The last element becomes the first one.
** rrr : rra and rrb at the same time.									>>> 9
*/

void	check_empty_act(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != '\n')
			j++;
		if (j == 2 || j == 3)
			i += j;
		else
			end_error();
		i++;
	}
}

void	get_n_check_act(char *tail)
{
	char	**act;
	int		i;

	if (tail == NULL)
		check_sort(0);
	check_empty_act(tail);
	act = ft_strsplit(tail, '\n');
	t_v.act = act;
	i = 0;
	while (act[i])
	{
		if (act[i] == NULL || check_act(act[i]))
			end_error();
		i++;
	}
	spin_act(act);
}

void	read_act(void)
{
	char	buff[BUFF_SIZE + 1];
	char	*tail;
	char	*tmp;
	int		data;

	if ((read(0, buff, 0)) < 0)
		end_error();
	tmp = NULL;
	tail = NULL;
	while ((data = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[data] = '\0';
		if (tail == NULL)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(tail, buff);
		if (tail)
			free(tail);
		tail = tmp;
	}
	t_v.tail = tail;
	get_n_check_act(tail);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_a.gc = argc;
		t_a.gv = &argv;
		t_a.sz_m = 0;
		reset_options();
		check_n_get_argv(1);
		check_dupl();
		read_act();
		check_sort(0);
	}
	exit(0);
}
