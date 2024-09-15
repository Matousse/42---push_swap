/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:00:38 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 23:41:47 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_b_cost(t_struct *stru, int num)
{
	int	cost_r;
	int	cost_rr;
	int	i;

	cost_r = 1;
	cost_rr = 1;
	i = 1;
	if (num == stru->tabb[0])
		return (0);
	while (num != stru->tabb[i])
	{
		cost_r++;
		i++;
	}
	i = (stru->nb - 1);
	while (num != stru->tabb[i])
	{
		cost_rr++;
		i--;
	}
	if (cost_r <= cost_rr)
		return (cost_r);
	else
		return (-cost_rr);
}

int	calculate_real_cost_first(t_struct *stru, int b_cost, int a_cost)
{
	int	inter;

	stru->min_cost_indice = 0;
	if (b_cost > 0 && a_cost > 0)
	{
		inter = abs(b_cost - a_cost);
		return (b_cost + a_cost + inter);
	}
	else if (b_cost < 0 && a_cost < 0)
	{
		inter = abs(b_cost - a_cost);
		return (abs(b_cost) + abs(a_cost - inter));
	}
	else
		return (abs(b_cost) + abs(a_cost));
}

// void	algo_five(int *tab, int n)
// {
// 	int	big_node;
// 	int	small_node;

// 	big_node = maximum_value(tab, n);
// 	if (tab[0] == big_node)
// 		rotate_a(tab, n, 0)
// 	push_a
// 	else if (big_node == tab[1])
// 		rrotate_a(tab, n, 0);
// 	if (tab[0] > tab[1])
// 		swap_a(tab, n);
// }

// 		else if (stru->na <= 5)
// 			algo_five(stru->taba, stru->na);
