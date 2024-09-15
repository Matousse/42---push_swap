/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:42:06 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/26 00:12:41 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *c)
{
	if (*c == '-' || *c == '+')
	{
		c++;
	}
	if (*c == '\0')
	{
		write(1, "One argument is null", 20);
		return (0);
	}
	while (*c != '\0')
	{
		if (!ft_isdigit(*c))
		{
			return (0);
		}
		c++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	stru;

	stru.na = 0;
	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		if (argctwo(&stru, argv) == -1)
			return (0);
	}
	else
	{
		if (launch_algo(&stru, argv) == -1)
			return (0);
	}
	free(stru.taba);
	free(stru.tabb);
	return (0);
}

int	calloc_the_args(t_struct *stru, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (checkifintmax(argv) == -1)
		return (-1);
	while (argv[++i])
	{
		j = 1;
		if (is_int(argv[i]) == 0)
			return (ft_printf("Error\n"), -1);
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && (i != j))
				return (ft_printf("Error\n"), -1);
			j++;
		}
	}
	if (alloc_stru(stru, i) == -1)
		return (-1);
	while (i-- >= 2)
		stru->taba[i - 1] = (int)ft_atoi(argv[i]);
	return (0);
}

int	launch_algo(t_struct *stru, char **argv)
{
	if (calloc_the_args(stru, argv) == -1)
		return (-1);
	if (!is_tab_sorted(stru->taba, stru->na))
	{
		if (stru->na == 2)
			swap_a(stru->taba, stru->na);
		else if (stru->na == 3)
			algo_three(stru->taba, stru->na);
		else
			algo(stru);
	}
	return (0);
}

int	argctwo(t_struct *stru, char **argv)
{
	int	i;

	if (argv[1][0] == 0)
		return (-1);
	if (check_str(argv[1]) == -1)
		return (ft_printf("Error\n"), -1);
	if (ft_split_to_int(argv[1], ' ', stru) == -1)
		return (-1);
	if (checkifdoublons(stru) == -1)
		return (-1);
	i = 0;
	stru->tabb = malloc(sizeof(int) * stru->na);
	stru->nb = 0;
	if (is_tab_sorted(stru->taba, stru->na))
		return (0);
	if (stru->na == 2)
		swap_a(stru->taba, stru->na);
	else if (stru->na == 3)
		algo_three(stru->taba, stru->na);
	else
		algo(stru);
	return (0);
}

// if (argc == 2)
// 	tab1 = ft_split_to_int_tab(argv[1], '\n');
// else
/*	while (1)
	{
		printf("Enter command (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
			rrr)\n ");
			scanf("%s", command);
		if (strcmp(command, "sa") == 0)
			swap_x(stru.taba, stru.na);
		else if (strcmp(command, "sb") == 0)
			swap_x(stru.tabb, stru.nb);
		else if (strcmp(command, "ss") == 0)
			swap_both(stru.taba, stru.tabb, stru.na, stru.nb);
		else if (strcmp(command, "pa") == 0)
			push_x(stru.taba, stru.tabb, &stru.na, &stru.nb);
		else if (strcmp(command, "pb") == 0)
			push_x(stru.tabb, stru.taba, &stru.nb, &stru.na);
		else if (strcmp(command, "ra") == 0)
			rotate_x(stru.taba, stru.na);
		else if (strcmp(command, "rb") == 0)
			rotate_x(stru.tabb, stru.nb);
		else if (strcmp(command, "rr") == 0)
			rotate_both(stru.taba, stru.tabb, stru.na, stru.nb);
		else if (strcmp(command, "rra") == 0)
			rrotate_x(stru.taba, stru.na);
		else if (strcmp(command, "rrb") == 0)
			rrotate_x(stru.tabb, stru.nb);
		else if (strcmp(command, "rrr") == 0)
			rrotate_both(stru.taba, stru.tabb, stru.na, stru.nb);
		else
			printf("Invalid command\n");
		print_tabs(stru);
	}
*/
