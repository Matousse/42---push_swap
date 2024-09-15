/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:27:44 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/26 00:15:23 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alloc_stru(t_struct *stru, int i)
{
	stru->taba = malloc((i - 1) * sizeof(int));
	if (stru->taba == NULL)
		return (-1);
	stru->na = i - 1;
	stru->tabb = malloc((i - 1) * sizeof(int));
	if (stru->tabb == NULL)
	{
		if (stru->taba)
			free(stru->taba);
		return (-1);
	}
	stru->nb = 0;
	return (0);
}

int	ft_split_to_int(char const *str, char c, t_struct *stru)
{
	if (ft_split_2(str, c, stru) == -1)
		return (-1);
	if (stru->taba == NULL)
		return (-1);
	stru->na = stru->size;
	if (stru->size == 1)
	{
		free(stru->taba);
		return (-1);
	}
	return (0);
}

int	checkifdoublons(t_struct *stru)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stru->na)
	{
		j = 0;
		while (j < stru->na)
		{
			if (stru->taba[i] == stru->taba[j] && i != j)
			{
				free(stru->taba);
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	checkifintmax(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 9999999999)
		{
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	checkifintmax2(char **tab, t_struct *stru)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) == 9999999999)
		{
			while (tab[j])
				free(tab[j++]);
			free(tab);
			free(stru->taba);
			tab = NULL;
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
