/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:43:17 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 23:21:47 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_real_cost(int b_cost, int a_cost)
{
	int	inter;

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

void	migrate_to_a(t_struct *stru, int indice)
{
	if (indice == 0 && stru->total_cost == 0)
		return ((void)push_a(stru->taba, stru->tabb, &stru->na, &stru->nb));
	while (stru->cost_a > 0 && stru->cost_b > 0)
	{
		rotate_both(stru->tabb, stru->taba, stru->nb, stru->na);
		stru->cost_a--;
		stru->cost_b--;
	}
	while (stru->cost_a < 0 && stru->cost_b < 0)
	{
		rrotate_both(stru->tabb, stru->taba, stru->nb, stru->na);
		stru->cost_a++;
		stru->cost_b++;
	}
	while (stru->cost_a > 0)
	{
		rotate_a(stru->taba, stru->na, 0);
		stru->cost_a--;
	}
	migrate_to_a2(stru);
}

void	migrate_to_a2(t_struct *stru)
{
	while (stru->cost_a < 0)
	{
		rrotate_a(stru->taba, stru->na, 0);
		stru->cost_a++;
	}
	while (stru->cost_b > 0)
	{
		rotate_b(stru->tabb, stru->nb, 0);
		stru->cost_b--;
	}
	while (stru->cost_b < 0)
	{
		rrotate_b(stru->tabb, stru->nb, 0);
		stru->cost_b++;
	}
	push_a(stru->taba, stru->tabb, &stru->na, &stru->nb);
}

int	maximum_value(int *tab, size_t n)
{
	int		max;
	size_t	i;

	max = tab[0];
	i = 0;
	while (i < n)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	minimum_value(int *tab, size_t n)
{
	size_t	i;
	int		min;

	min = tab[0];
	i = 0;
	while (i < n)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}
