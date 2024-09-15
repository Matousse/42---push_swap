/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:39:22 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 22:04:08 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_tab_sorted(int *tab, size_t n)
{
	size_t	i;
	int		flag;

	flag = 0;
	i = 0;
	while (i < (n - 1) && flag == 0)
	{
		if (tab[i] > tab[i + 1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

// void	print_tabs(t_struct stru)
// {
// 	size_t	i;

// 	i = 0;
// 	printf("\nStack a de size %zu\n", stru.na);
// 	while (i < stru.na)
// 	{
// 		printf("%d\n", stru.taba[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("\nStack b de size %zu\n", stru.nb);
// 	while (i < stru.nb)
// 	{
// 		printf("%d\n", stru.tabb[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			return (-1);
		if (str[i + 1] && str[i] == '-' && str[i + 1] == '-')
			return (-1);
		if (str[i + 1] && ft_isdigit(str[i]) == 1 && str[i + 1] == '-')
			return (-1);
		i++;
	}
	return (0);
}
