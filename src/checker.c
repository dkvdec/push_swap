/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:08:49 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 17:00:20 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
**		Do nothing if there is only one or no elements).
** sb : swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there	is only one or no elements).
** ss : sa and sb at the same time.
** pa : push a - take the first element at the top of b and put
**		it at the top of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put
**		it at the top of b. Do nothing if a is empty.
** ra : rotate a - shift up all elements of stack a by 1.
**		The first element becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1.
**		The first element becomes the last one.
** rr : ra and rb at the same time.
** rra : reverse rotate a - shift down all elements of stack a by 1.
**		The last element becomes the first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1.
**		The last element becomes the first one.
** rrr : rra and rrb at the same time.
*/

void	get_n_check_act(char *tail)
{
	char	**act;
	int		i;

	if (tail != NULL)
	{
		act = ft_strsplit(tail, '\n');
		i = 0;
		while (act[i])
		{
			if (check_act(act[i]))
				end_error();
			i++;
		}
		spin_act(act);
	}
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
	get_n_check_act(tail);
}

int		main(int argc, char **argv)
{
	char *line;

	if (argc > 1)
	{
		t_a.gc = argc;
		t_a.gv = &argv;
		t_a.sz_m = 0;
		check_n_get_argv();
		check_dupl();
		read_act();
		check_sort(0);
	}
	exit(0);
}
