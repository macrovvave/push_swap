/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:59:04 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/28 23:11:08 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorting(t_stack *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*get_high(t_stack *stacka)
{
	t_stack	*high_node;
	int		high;

	if (stacka == NULL)
		return (NULL);
	high_node = NULL;
	high = INT_MIN;
	while (stacka)
	{
		if (stacka->value > high)
		{
			high = stacka->value;
			high_node = stacka;
		}
		stacka = stacka->next;
	}
	return (high_node);
}

void	sort(t_stack **stacka)
{
	t_stack	*high;

	high = get_high(*stacka);
	if (*stacka == high)
		ra(stacka, false);
	else if ((*stacka)->next == high)
		rra(stacka, false);
	if ((*stacka)->value > (*stacka)->next->value)
		sa(stacka, false);
}

void	ft_f(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);	
}
