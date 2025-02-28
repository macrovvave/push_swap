/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:37 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/28 23:02:15 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**tab;

	t_stack *(a), *(b);
	a = NULL;
	b = NULL;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		ft_prepare(&a, (tab = ft_split(av[1], ' ')));
		ft_f(tab);
	}
	else
		ft_prepare(&a, av + 1);
	printf("---> 1 <---\n");
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
