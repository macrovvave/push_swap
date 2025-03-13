/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:37 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/03/13 02:13:31 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

void	check_arg_lenght(char **av)
{
	int (i), (j), (check), (len);
	i = 0;
	while (av[i])
	{
		check = 1;
		j = 0;
		len = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '1' && av[i][j] <= '9')
				check = 0;
			if ((av[i][j] >= '0' && av[i][j] <= '9') && check == 0)
				len++;
			if (av[i][j] == ' ')
			{
				len = 0;
				check = 1;
			}
			j++;
			if (len > 10)
				ft_exit();
		}
		i++;
	}
}

void	check(char **av)
{
	int (i), (u), (c);
	i = 0;
	while (av[i])
	{
		u = 0;
		c = 0;
		while (av[i][u])
		{
			if(av[i][u] != ' ' && av[i][u] != '\t' && av[i][u] != '\n')
				c++;
			u++;
		}
		if (c == 0)
			ft_exit();
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack *(a), *(b);
	a = NULL;
	b = NULL;
	if (1 == ac)
		return (1);
	check_arg_lenght(av);
	check(av);
	ft_prepare2(&a, av + 1);
	if (!stack_sorting(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort(&a);
		else
			push_swap(&a, &b);
	}
	ft_stackclear(&a);
	return (0);
}
