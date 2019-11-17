/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:22:57 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/17 15:26:37 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 12

# include "../libft/libft.h"

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
** NUMBERS CHECK_N_GET FUNCTIONS
*/

int			exception_check(char *str, int i);
int			nbr_check(char *str, int *i);
int			line_pass(char *str);
int			count_nbrs(void);
int			grep_nbrs(char *str, int *j);
int			get_nbrs(void);

/*
** PROGRAM TAILS
*/

void		end_error(void);
void		end_ok(void);
void		end_ko(void);

/*
** ADDITIONAL CHECK FUNCTIONS
*/

void		check_n_get_argv(void);
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

#endif
