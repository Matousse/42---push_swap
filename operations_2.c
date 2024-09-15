/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:55:49 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 16:30:04 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *tabx, size_t nx, int flag)
{
	int		first_to_last;
	size_t	i;

	if (nx == 0 || nx == 1)
	{
		swap_a_silent(tabx, nx);
		if (flag == 0)
			ft_printf("ra\n");
		return ;
	}
	first_to_last = tabx[0];
	i = 0;
	while (i < nx - 1)
	{
		tabx[i] = tabx[i + 1];
		i++;
	}
	tabx[i] = first_to_last;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rotate_b(int *tabx, size_t nx, int flag)
{
	int		first_to_last;
	size_t	i;

	if (nx == 0 || nx == 1)
		return ;
	if (nx == 2)
	{
		swap_b_silent(tabx, nx);
		if (flag == 0)
			ft_printf("rb\n");
		return ;
	}
	first_to_last = tabx[0];
	i = 0;
	while (i < nx - 1)
	{
		tabx[i] = tabx[i + 1];
		i++;
	}
	tabx[i] = first_to_last;
	if (flag == 0)
		ft_printf("rb\n");
}

void	rotate_both(int *tabx, int *taby, size_t nx, size_t ny)
{
	rotate_a(tabx, nx, 1);
	rotate_b(taby, ny, 1);
	ft_printf("rr\n");
}

void	rrotate_a(int *tabx, size_t nx, int flag)
{
	int		last_to_first;
	size_t	i;

	if (nx == 0 || nx == 1)
		return ;
	if (nx == 2)
	{
		swap_a_silent(tabx, nx);
		if (flag == 0)
			ft_printf("rra\n");
		return ;
	}
	last_to_first = tabx[nx - 1];
	i = nx - 1;
	while (i > 0)
	{
		tabx[i] = tabx[i - 1];
		i--;
	}
	tabx[i] = last_to_first;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrotate_b(int *tabx, size_t nx, int flag)
{
	int		last_to_first;
	size_t	i;

	if (nx == 0 || nx == 1)
		return ;
	if (nx == 2)
	{
		swap_b_silent(tabx, nx);
		if (flag == 0)
			ft_printf("rra\n");
		return ;
	}
	last_to_first = tabx[nx - 1];
	i = nx - 1;
	while (i > 0)
	{
		tabx[i] = tabx[i - 1];
		i--;
	}
	tabx[i] = last_to_first;
	if (flag == 0)
		ft_printf("rrb\n");
}
