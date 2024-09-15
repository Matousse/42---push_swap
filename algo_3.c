/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:44:32 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 17:00:29 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_index(int *tab, int num)
{
	size_t	i;

	i = 0;
	while (tab[i] != num)
	{
		i++;
	}
	return (i);
}

void	order_taba(t_struct *stru, int num)
{
	while (count_index(stru->taba, num) > (stru->na / 2)
		&& stru->taba[0] != num)
		rrotate_a(stru->taba, stru->na, 0);
	while (count_index(stru->taba, num) <= (stru->na / 2)
		&& stru->taba[0] != num)
		rotate_a(stru->taba, stru->na, 0);
}

void	order_tabb(t_struct *stru, int num)
{
	if (stru->nb == 0 || stru->nb == 1)
		return ;
	while (count_index(stru->tabb, num) > (stru->nb / 2)
		&& stru->tabb[0] != num)
	{
		rrotate_b(stru->tabb, stru->nb, 0);
	}
	while (count_index(stru->tabb, num) <= (stru->nb / 2)
		&& stru->tabb[0] != num)
	{
		rotate_b(stru->tabb, stru->nb, 0);
	}
}

int	calculate_a_cost_r(t_struct *stru, int num)
{
	int	cost_r;
	int	i;

	cost_r = 1;
	i = 0;
	while (!(num > stru->taba[i] && num < stru->taba[i + 1]))
	{
		cost_r++;
		i++;
	}
	return (cost_r);
}

int	calculate_a_cost_rr(t_struct *stru, int num)
{
	int	cost_rr;
	int	i;

	cost_rr = 1;
	i = (stru->na - 1);
	while (!(num < stru->taba[i] && num > stru->taba[i - 1]))
	{
		cost_rr++;
		i--;
	}
	return (cost_rr);
}
