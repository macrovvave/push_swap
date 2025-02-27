/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:41 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/13 13:59:55 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->inorout = true;
		else
			stack->inorout = false;
		stack = stack->next;
		++i;
	}
}

void	get_wanted_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->wanted_node = get_smallest(a);
		else
			b->wanted_node = target_node;
		b = b->next;
	}
}

void	get_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->inorout))
			b->push_cost = len_b - (b->current_position);
		if (b->wanted_node->inorout)
			b->push_cost += b->wanted_node->current_position;
		else
			b->push_cost += len_a - (b->wanted_node->current_position);
		b = b->next;
	}
}

void	get_theone(t_stack *b)
{
	long	best_value;
	t_stack	*the_one;

	if (NULL == b)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			the_one = b;
		}
		b = b->next;
	}
	the_one->theone = true;
}

void	nodes_data(t_stack *a, t_stack *b)
{
	get_current_position(a);
	get_current_position(b);
	get_wanted_node(a, b);
	get_cost(a, b);
	get_theone(b);
}
