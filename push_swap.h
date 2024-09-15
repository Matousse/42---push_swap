/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:36:06 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/26 00:08:24 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct traine_bouzin
{
	int		*taba;
	int		*tabb;
	size_t	na;
	size_t	nb;
	int		total_cost;
	int		cost_a;
	int		cost_b;
	int		min_cost_indice;
	int		size;
}			t_struct;

//main.c
int			is_int(char *c);
int			ft_split_to_int(char const *str, char c, t_struct *stru);
int			launch_algo(t_struct *stru, char **argv);
int			calloc_the_args(t_struct *stru, char **argv);
int			argctwo(t_struct *stru, char **argv);
int			alloc_stru(t_struct *stru, int i);
int			ft_split_2(char const *str, char c, t_struct *stru);
int			checkifdoublons(t_struct *stru);
int			checkifintmax(char **argv);
int			checkifintmax2(char **tab, t_struct *stru);

// operations_1.c
void		swap_a(int *tabx, size_t n);
void		swap_b(int *tabx, size_t n);
void		swap_a_silent(int *tabx, size_t n);
void		swap_b_silent(int *tabx, size_t n);
void		push_a(int *tabx, int *taby, size_t *nx, size_t *ny);
void		push_b(int *tabx, int *taby, size_t *nx, size_t *ny);
void		swap_both(int *tab1, int *tab2, size_t n1, size_t n2);

// operations_2.c
void		rotate_a(int *tabx, size_t nx, int i);
void		rotate_b(int *tabx, size_t nx, int i);
void		rrotate_a(int *tabx, size_t nx, int i);
void		rrotate_b(int *tabx, size_t nx, int i);
void		rotate_both(int *tabx, int *taby, size_t nx, size_t ny);
void		rrotate_both(int *tabx, int *taby, size_t nx, size_t ny);
void		rotate_both_multiple(t_struct *stru, size_t a, size_t b);
void		rrotate_both_multiple(t_struct *stru, size_t a, size_t b);

// algo.c
void		algo(t_struct *stru);
int			orchester_to_a(t_struct *stru);
int			calculate_abs_cost(t_struct *stru, int num);
int			cost_abs_to_reach(t_struct *stru, int num);
int			calculate_cost_to_migrate(t_struct *stru, int num);
void		calculate_best_cost_b_to_a(t_struct *stru);
int			calculate_b_cost(t_struct *stru, int num);
int			calculate_a_cost(t_struct *stru, int num);
int			calculate_real_cost(int b_cost, int a_cost);
void		migrate_to_a(t_struct *stru, int indice);
void		migrate_to_a2(t_struct *stru);
int			maximum_value(int *tab, size_t n);
int			minimum_value(int *tab, size_t n);
size_t		count_index(int *tab, int num);
void		order_taba(t_struct *stru, int num);
void		algo_three(int *tab, int n);
int			calculate_a_cost_r(t_struct *stru, int num);
int			calculate_a_cost_rr(t_struct *stru, int num);
int			calculate_a_cost_first_check(t_struct *stru);
int			calculate_real_cost_first(t_struct *stru, int b_cost, int a_cost);

// utils.c
int			is_tab_sorted(int *tab, size_t n);
void		print_tabs(t_struct stru);
void		order_tabb(t_struct *stru, int num);
int			check_str(char *str);

#endif
