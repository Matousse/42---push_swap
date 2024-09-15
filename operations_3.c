/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:29:22 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 16:41:17 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_both(int *tabx, int *taby, size_t nx, size_t ny)
{
	rrotate_a(tabx, nx, 1);
	rrotate_b(taby, ny, 1);
	ft_printf("rrr\n");
}

void	swap_a_silent(int *tabx, size_t n)
{
	int	temp;

	if (n <= 1)
		return ;
	temp = tabx[1];
	tabx[1] = tabx[0];
	tabx[0] = temp;
}

void	swap_b_silent(int *tabx, size_t n)
{
	int	temp;

	if (n <= 1)
		return ;
	temp = tabx[1];
	tabx[1] = tabx[0];
	tabx[0] = temp;
}
