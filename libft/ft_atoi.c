/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:24:10 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/25 23:04:33 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)

{
	int		i;
	long	entier;
	int		minus;

	minus = 1;
	i = 0;
	entier = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		entier = entier * 10 + str[i] - '0';
		i++;
	}
	if ((entier * minus) > 2147483647 || (entier * minus) < -2147483648)
		return (9999999999);
	return (entier * minus);
}
