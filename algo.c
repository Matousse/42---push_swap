/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:46:43 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 23:41:11 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_struct *stru)
{
	size_t	i;
	int		max_a;
	size_t	max_na;

	i = 0;
	max_a = maximum_value(stru->taba, stru->na);
	max_na = stru->na;
	stru->total_cost = 0;
	while (i < max_na && stru->na > 5)
	{
		if (stru->taba[0] > (max_a / 2))
			push_b(stru->tabb, stru->taba, &stru->nb, &stru->na);
		else
			rotate_a(stru->taba, stru->na, 0);
		i++;
	}
	while (stru->na > 3)
		push_b(stru->tabb, stru->taba, &stru->nb, &stru->na);
	algo_three(stru->taba, stru->na);
	while (stru->nb > 0)
	{
		calculate_best_cost_b_to_a(stru);
		migrate_to_a(stru, stru->min_cost_indice);
	}
	order_taba(stru, minimum_value(stru->taba, stru->na));
}

void	algo_three(int *tab, int n)
{
	int	big_node;

	big_node = maximum_value(tab, n);
	if (big_node == tab[0])
		rotate_a(tab, n, 0);
	else if (big_node == tab[1])
		rrotate_a(tab, n, 0);
	if (tab[0] > tab[1])
		swap_a(tab, n);
}

void	calculate_best_cost_b_to_a(t_struct *stru)
{
	size_t	i;
	int		b_cost;
	int		a_cost;
	int		total_cost_temp;

	b_cost = calculate_b_cost(stru, stru->tabb[0]);
	a_cost = calculate_a_cost(stru, stru->tabb[0]);
	stru->total_cost = calculate_real_cost_first(stru, b_cost, a_cost);
	stru->cost_a = a_cost;
	stru->cost_b = b_cost;
	i = 1;
	while (i < stru->nb)
	{
		b_cost = calculate_b_cost(stru, stru->tabb[i]);
		a_cost = calculate_a_cost(stru, stru->tabb[i]);
		total_cost_temp = calculate_real_cost(b_cost, a_cost);
		if ((total_cost_temp) < stru->total_cost)
		{
			stru->total_cost = total_cost_temp;
			stru->min_cost_indice = i;
		}
		i++;
	}
	stru->cost_a = calculate_a_cost(stru, stru->tabb[stru->min_cost_indice]);
	stru->cost_b = calculate_b_cost(stru, stru->tabb[stru->min_cost_indice]);
}

int	calculate_a_cost(t_struct *stru, int num)
{
	int	cost_r;
	int	cost_rr;

	if (stru->na == 0 || stru->na == 1)
		return (0);
	if (num > maximum_value(stru->taba, stru->na)
		|| (num < minimum_value(stru->taba, stru->na)))
		return (calculate_a_cost_first_check(stru));
	cost_rr = 1;
	if (num < stru->taba[0] && num > stru->taba[stru->na - 1])
		return (0);
	cost_r = calculate_a_cost_r(stru, num);
	cost_rr = calculate_a_cost_rr(stru, num);
	if (cost_r <= cost_rr)
		return (cost_r);
	else
		return (-cost_rr);
}

int	calculate_a_cost_first_check(t_struct *stru)
{
	int	cost;

	cost = count_index(stru->taba, (size_t)minimum_value(stru->taba,
				stru->na));
	if (cost > (int)(stru->na / 2))
		return (-(int)(stru->na - cost));
	else
		return ((int)cost);
}
