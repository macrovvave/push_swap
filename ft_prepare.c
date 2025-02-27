/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:44 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/13 13:59:55 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result * sign);
}

void	ft_prepare(t_stack **a, char **av)
{
	long	num;
	int		index;

	index = 0;
	while (av[index])
	{
		if (ft_syntax(av[index]))
			ft_free(a);
		num = ft_atoi(av[index]);
		if (num > INT_MAX || num < INT_MIN)
			ft_free(a);
		if (ft_repetition(*a, (int)num))
			ft_free(a);
		num = ft_atoi(av[index]);
		ft_append(a, (int)num);
		index++;
	}
}
