/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:27 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/03/01 15:06:20 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_syntax(char *str)
{
	int	i;

	i = 0;
	if (!((str[i] == '+' || str[i] == '-')
			|| (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

int	ft_repetition(t_stack *a, int num, size_t sign)
{
	if (NULL == a)
		return (0);
	if (sign == 0)
		num *= -1;
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_free(t_stack **a, char **av, int check)
{
	unsigned int	i;

	if (check == 1)
	{
		i = 0;
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
		ft_stackclear(a);
		write(1, "Error\n", 6);
		exit(0);
	}
	else if (check == 2)
	{
		ft_stackclear(a);
		write(1, "Error\n", 6);
		exit(0);
	}
}
