/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:16:51 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 16:41:07 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *tabx, size_t n)
{
	int	temp;

	if (n <= 1)
		return ;
	temp = tabx[1];
	tabx[1] = tabx[0];
	tabx[0] = temp;
	ft_printf("sa\n");
}

void	swap_b(int *tabx, size_t n)
{
	int	temp;

	if (n <= 1)
		return ;
	temp = tabx[1];
	tabx[1] = tabx[0];
	tabx[0] = temp;
	ft_printf("sb\n");
}

void	swap_both(int *tab1, int *tab2, size_t n1, size_t n2)
{
	swap_a(tab1, n1);
	swap_b(tab2, n2);
	ft_printf("ss\n");
	return ;
}

void	push_a(int *tabx, int *taby, size_t *nx, size_t *ny)
{
	size_t	i;

	if (*ny == 0)
		return ;
	i = (*nx)++;
	if (i > 1)
	{
		while (i-- > 0)
			tabx[i + 1] = tabx[i];
	}
	tabx[0] = taby[0];
	*ny -= 1;
	i = 0;
	while (i < *ny)
	{
		taby[i] = taby[i + 1];
		i++;
	}
	return ((void)ft_printf("pa\n"));
}

void	push_b(int *tabx, int *taby, size_t *nx, size_t *ny)
{
	size_t	i;

	if (*ny == 0)
		return ;
	i = *nx;
	if (*nx > 0)
	{
		while (i != 0)
		{
			tabx[i] = tabx[i - 1];
			i --;
		}
	}
	*nx += 1;
	*ny -= 1;
	tabx[0] = taby[0];
	i = 0;
	while (i < *ny)
	{
		taby[i] = taby[i + 1];
		i++;
	}
	ft_printf("pb\n");
	return ;
}
