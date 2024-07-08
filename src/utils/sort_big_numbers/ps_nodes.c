/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:04 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 19:03:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>
#include "libft.h"

static t_stack_node	*get_least(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->least_moves)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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

static void	rotate_both(t_stack_node **a, \
		t_stack_node **b, t_stack_node *least_node)
{
	while (*a != least_node->target_node && *b != least_node)
		rr(a, b);
	set_indice(*a);
	set_indice(*b);
}

static void	rev_rotate_both(t_stack_node **a, \
		t_stack_node **b, t_stack_node *least_node)
{
	while (*a != (least_node->target_node) && *b != least_node)
		rrr(a, b);
	set_indice(*a);
	set_indice(*b);
}

void	push_swap_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_least_moves;

	node_least_moves = get_least(*b);
	if (node_least_moves->before_median && \
			node_least_moves->target_node->before_median)
		rotate_both(a, b, node_least_moves);
	else if (!(node_least_moves->before_median) && \
			!(node_least_moves->target_node->before_median))
		rev_rotate_both(a, b, node_least_moves);
	check_rotate_node(b, node_least_moves, 'b');
	check_rotate_node(a, node_least_moves->target_node, 'a');
	papb(b, a, "pa");
}
