/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:51 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/26 00:06:31 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_maison_2(char **tab, int nbw)
{
	int	k;

	k = 0;
	while (k < nbw)
	{
		free(tab[k]);
		k++;
	}
	free(tab);
}

char	*my_strcpy_2(char *dest, const char *src, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = dest;
	while (i < n)
	{
		*ptr++ = *src++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}

int	countwords_2(char const *str, char c, t_struct *stru)
{
	int	nbw;
	int	i;

	i = 0;
	nbw = 0;
	while ((str[i] == c) && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			if ((str[i + 1] == c || str[i + 1] == '\0'))
				nbw += 1;
		}
		i++;
	}
	stru->size = nbw;
	return (nbw);
}

char	**createchains_2(char const *str, char c, char **tab, int nbw)
{
	int	i;
	int	currentw;
	int	j;

	i = 0;
	currentw = 0;
	while (currentw < nbw)
	{
		while ((str[i] == c) && str[i])
			i++;
		j = i;
		while ((str[i] != c) && str[i])
			i++;
		tab[currentw] = malloc(sizeof(char) * (i - j + 1));
		if (tab[currentw] == NULL)
		{
			free_maison_2(tab, currentw);
			return (NULL);
		}
		tab[currentw] = my_strcpy_2(tab[currentw], &str[j], i - j);
		currentw++;
	}
	tab[currentw] = 0;
	return (tab);
}

int	ft_split_2(char const *str, char c, t_struct *stru)
{
	int		nbw;
	char	**tab;
	int		i;

	i = 0;
	nbw = countwords_2(str, c, stru);
	stru->taba = malloc(sizeof(int) * stru->size);
	tab = malloc((sizeof(char *) * (nbw + 1)));
	if (tab == NULL || stru->taba == NULL)
		return (-1);
	tab = createchains_2(str, c, tab, nbw);
	if (checkifintmax2(tab, stru) == -1)
		return (-1);
	while (tab[i])
	{
		stru->taba[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
	return (0);
}
