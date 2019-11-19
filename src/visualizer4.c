/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:38:18 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/19 20:11:24 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	show_ok(void)
{
	int i;

	i = 100;
	while (i-- > 1)
		write(1, "\n", 1);
	ft_printf("{g+}      OKOKOK           OK           OK\n");
	ft_printf("    OK      OK         OK         OK\n");
	ft_printf("  OK          OK       OK       OK\n");
	ft_printf("OK              OK     OK     OK\n");
	ft_printf("OK              OK     OK   OK\n");
	ft_printf("OK              OK     OKOK\n");
	ft_printf("OK              OK     OK  OK\n");
	ft_printf("OK              OK     OK    OK\n");
	ft_printf("  OK          OK       OK      OK\n");
	ft_printf("    OK      OK         OK        OK\n");
	ft_printf("      OKOKOK           OK          OK{w-}\n");
	while (i < t_v.t)
	{
		(i < t_a.sz_m / 2) ? ft_printf("\n") : 0;
		i++;
	}
	while (i > 1)
		i--;
}

void	show_ko(void)
{
	int i;

	i = 100;
	while (i-- > 1)
		ft_printf("\n");
	ft_printf("{r+}KO           KO          KOKOKO\n");
	ft_printf("KO         KO          KO      KO\n");
	ft_printf("KO       KO          KO          KO\n");
	ft_printf("KO     KO          KO              KO\n");
	ft_printf("KO   KO            KO              KO\n");
	ft_printf("KOKO               KO              KO\n");
	ft_printf("KO  KO             KO              KO\n");
	ft_printf("KO    KO           KO              KO\n");
	ft_printf("KO      KO           KO          KO\n");
	ft_printf("KO        KO           KO      KO\n");
	ft_printf("KO          KO           KOKOKO{w-}\n");
	while (i < t_v.t)
	{
		(i < t_a.sz_m / 2) ? ft_printf("\n") : 0;
		i++;
	}
	while (i > 1)
		i--;
}
