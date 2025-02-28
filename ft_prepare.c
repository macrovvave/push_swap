/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:44 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/28 21:25:49 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_atoi(char *str)
{
	int	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result);
}
#include <stdio.h>

void	ft_prepare(t_stack **a, char **av)
{
	size_t	num;
	int		index;
	int		sign;

	index = 0;
	sign = 1;
	while (av[index])
	{
		if(av[index][0] == '-')
			sign = 0;
		if (ft_syntax(av[index]) == 1)
		{
			ft_free(a, av);
		}
		printf("---> 2 <---\n");
		num = ft_atoi(av[index]);
		if (sign == 0 && num > 2147483648)
			ft_free(a, av);
		if (sign == 1 && num > 2147483647)
			ft_free(a, av);
		if (ft_repetition(*a, (int)num))
			ft_free(a, av);
		ft_append(a, (int)num);
		index++;
	}
}
