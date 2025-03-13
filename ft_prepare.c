/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:44 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/03/13 02:06:54 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

long	ft_atoi(char *str)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result);
}

int	free_tab(char **tab, int c)
{
	size_t	u;

	if (c == 1)
	{
		u = 0;
		while (tab[u])
		{
			free(tab[u]);
			u++;
		}
		free(tab);
		return (1);
	}
	else
	{
		u = 0;
		while (tab[u])
		{
			free(tab[u]);
			u++;
		}
		free(tab);
	}
	return (0);
}

int	ft_prep(t_stack **a, char *pum)
{
	char		**tab;

	long (i), (num), (sign);
	num = 0;
	sign = 1;
	i = 0;
	tab = ft_split(pum, ' ');
	while (tab[i])
	{
		if (tab[i][0] == '-')
			sign = 0;
		if (ft_syntax(tab[i]) == 1)
			return (free_tab(tab, 1));
		num = ft_atoi(tab[i]);
		if (sign == 0 && num > 2147483648)
			return (free_tab(tab, 1));
		if (sign == 1 && num > 2147483647)
			return (free_tab(tab, 1));
		if (ft_repetition(*a, (int)num, sign))
			return (free_tab(tab, 1));
		ft_append(a, (int)num, sign);
		sign = 1;
		i++;
	}
	return (free_tab(tab, 0));
}

void	ft_prepare2(t_stack **a, char **av)
{
	size_t	index;

	index = 0;
	while (av[index])
	{
		if (av[index][0] == '\0')
			ft_free(a, av, 2);
		if (ft_prep(a, av[index]))
			ft_free(a, av, 2);
		index++;
	}
}
