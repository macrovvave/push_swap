/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:51 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/03/13 23:59:14 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	struct s_stack	*wanted_node;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				value;
	int				current_position;
	int				wanted_index;
	int				push_cost;
	bool			inorout;
	bool			theone;
}	t_stack;

// sorting functions
bool	stack_sorting(t_stack *stack);
void	get_wanted_node(t_stack *a, t_stack *b);

void	ft_exit(void);
void	*ft_calloc(size_t count, size_t size);

void	nodes_data(t_stack *a, t_stack *b);
void	push_swap(t_stack **a, t_stack **b);
void	get_current_position(t_stack *stack);
void	sort(t_stack **stack);
void	get_cost(t_stack *a, t_stack *b);
void	nodes_data(t_stack *a, t_stack *b);
void	rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	ft_append(t_stack **a, int num, size_t sign);
void	ft_prepare1(t_stack **a, char **av);
void	ft_prepare2(t_stack **a, char **av);
void	ft_stackclear(t_stack **stack);
void	ft_free(t_stack **a, char **av, int check );
void	get_theone(t_stack *b);
void	swap(t_stack **head);
void	ft_f(char **tab);
void	ft_bzero(void *s, size_t n);
// void	*ft_ff(char	*buf);

int		ft_syntax(char *str);
int		ft_repetition(t_stack *a, int num, size_t sign);
int		stack_len(t_stack *satck);

long	ft_atoi(char *str);

char	**ft_split(char const *s, char c);

t_stack	*get_high(t_stack *stack);
t_stack	*get_smallest(t_stack *stack);
t_stack	*getlast(t_stack *head);
t_stack	*return_theone(t_stack *stackb);
// revers rotation commands

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool check);
void	rrb(t_stack **b, bool check);
void	rrr(t_stack **a, t_stack **b, bool check);
// push commands 
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);

// swap commands
void	swap(t_stack	**head);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

// rotate commands
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

#endif
