/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:47 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/03/11 21:46:36 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *wanted_node)
{
	while (*a != wanted_node->wanted_node
		&& *b != wanted_node)
		rr(a, b, false);
	get_current_position(*a);
	get_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *wanted_node)
{
	while (*a != wanted_node->wanted_node
		&& *b != wanted_node)
		rrr(a, b, false);
	get_current_position(*a);
	get_current_position(*b);
}

void	rotation(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->inorout)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (node->inorout)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*wanted_node;

	wanted_node = return_theone(*b);
	if (wanted_node->inorout
		&& wanted_node->wanted_node->inorout)
		rotate_both(a, b, wanted_node);
	else if (!(wanted_node->inorout)
		&& !(wanted_node->wanted_node->inorout))
		reverse_rotate_both(a, b, wanted_node);
	rotation(b, wanted_node, 'b');
	rotation(a, wanted_node->wanted_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a, false);
	sort(a);
	while (*b)
	{
		nodes_data(*a, *b);
		move_nodes(a, b);
	}
	get_current_position(*a);
	smallest = get_smallest(*a);
	if (smallest->inorout)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
