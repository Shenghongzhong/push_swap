/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:04 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 18:13:39 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>
#include "libft.h"

static t_stack_node	*get_least(t_stack_node *stack)
{
	t_stack_node	*least_moves_node;

	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->least_moves)
			least_moves_node = stack;
		stack = stack->next;
	}
	return (least_moves_node);
}

void	check_rotate_node(t_stack_node **stack, t_stack_node *top_node, \
		char which_stack)
{
	while (*stack != top_node)
	{
		if (which_stack == 'a')
		{
			if (top_node->before_median)
				rarb(stack, "ra");
			else
				rrota_ab(stack, "rra");
		}
		else if (which_stack == 'b')
		{
			if (top_node->before_median)
				rarb(stack, "rb");
			else
				rrota_ab(stack, "rrb");
		}
	}
}

void	push_swap_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_least_moves;

	node_least_moves = get_least(*b);
	if (node_least_moves->before_median && \
			node_least_moves->target_node->before_median)
	{
		while (*a != node_least_moves->target_node && \
				*b != node_least_moves)
			rr(a, b);
	}
	else if (!(node_least_moves->before_median) && \
			!(node_least_moves->target_node->before_median))
	{
		while (*a != node_least_moves->target_node && \
				*b != node_least_moves)
			rrr(a, b);
	}
	set_indice(*a);
	set_indice(*b);
	check_rotate_node(a, node_least_moves->target_node, 'a');
	check_rotate_node(b, node_least_moves, 'b');
	papb(b, a, "pa");
}
