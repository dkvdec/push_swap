/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:22:57 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 15:48:07 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 12
# include "../ft_printf/inc/proto_vlst.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct		s_a{
	int		gc;
	char	***gv;
	int		*ar_a;
	int		sz_a;
	int		*ar_b;
	int		sz_b;
	int		sz_m;
}			t_a;

struct		s_p{
	int		*pr_a;
	int		sz_c;
	int		sz_m;
}			t_p;

/*
** VISUALIZER OPTIONS
**
** v - visualizer on
** t(empty/nbr) - time to wait(int)
** h - head(counter in head)
** b - bot(current action and <^>)
** l - lock with colour target of last op
*/

struct		s_v{
	int		v;
	int		t;
	int		h;
	int		c;
	char	*c_c;
	int		b;
	int		l;
	int		ai;
	int		aai;
	int		bi;
	int		bbi;
	char	*tail;
	char	**act;
}			t_v;

/*
** NUMBERS CHECK_N_GET FUNCTIONS
*/

int			exception_check(char *str, int i);
int			nbr_check(char *str, int *i);
int			line_pass(char *str);
int			count_nbrs(int f);
int			grep_nbrs(char *str, int *j);
int			get_nbrs(int f);

/*
** PROGRAM TAILS
*/

void		end_error(void);
void		end_ok(void);
void		end_ko(void);

/*
** ADDITIONAL CHECK FUNCTIONS
*/

void		check_n_get_argv(int f);
void		check_dupl(void);
void		check_sort(int flag);
int			check_act(char *act);

/*
** ACTIONS CHECK_N_EXECUTE
*/

void		act_sa(int flag);
void		act_sb(int flag);
void		act_ss(int flag);
void		push_up(int flag);
void		push_down(int flag);
void		act_pa(int flag);
void		act_pb(int flag);
void		act_ra(int flag);
void		act_rb(int flag);
void		act_rr(int flag);
void		act_rra(int flag);
void		act_rrb(int flag);
void		act_rrr(int flag);
void		exec_act(char *act);
void		spin_act(char **act);
void		get_n_check_act(char *tail);
void		read_act(void);

/*
** PUSH_SWAP SORT FUNCTIONS
*/

void		sort_act(int act, int flag);
void		sort_stack(int flag);
void		sort_micro(int flag);
int			find_near(int i);
int			find_ent(int i);
int			count_price(int i, int j);
void		count_proto(void);
void		get_lowest(void);
void		sol_tt(int i, int j);
void		sol_bb(int i, int j);
void		sol_tb(int i, int j);
void		sol_bt(int i, int j);
void		do_actions(void);
void		ext_rotate(void);
void		sort_proto(void);
void		collector(void);
void		sort_core(void);

/*
** VISUALIZER
*/

void		show_head(void);
void		get_symbols3(char ***ca, char ***cb, char *com);
void		get_symbols2(char **ca, char **cb, char *com);
void		get_symbols(char *ca, char *cb, char *com);
void		show_bot(char *com);
void		show_body(int i);
void		get_mark2(void);
void		get_mark(void);
void		show_body_ext2(int i);
void		show_body_ext(int i);
void		show_stacks(char *com);
void		show_stacks_core(char *com, void (*f)(int), int flag);
void		reset_options(void);
int			wait_options(char *str, int i);
int			check_options(char *str, int i);

#endif
