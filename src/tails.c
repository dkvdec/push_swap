/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tails.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:38:29 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 18:37:23 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	end_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	end_ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void	end_ko(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	end_ok_v(void)
{
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("FNL");
	show_ok();
	show_stacks("OK");
	exit(0);
}

void	end_ko_v(void)
{
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("FNL");
	show_ko();
	show_stacks("KO");
	exit(0);
}
