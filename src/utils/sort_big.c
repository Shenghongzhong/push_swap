/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:04 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 10:37:17 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>
#include "libft.h"

void	set_indice(t_stack_node *a)
{
	int	i;
	int	median;

	i = 0;
	if (a == NULL)
		return ;
	if (ft_dblst_size(a) % 2 != 0)
		median = (ft_dblst_size(a) + 1) / 2;
	else 
		median = ft_dblst_size(a) / 2;
	while (a)
	{
		a->idx = i;
		if (i < median)
			a->before_median = true;
		else
			a->before_median = false;
		a = a->next;
		i++;
	}
}

t_stack_node	*search_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->data < smallest)
		{
			smallest = stack->data;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	set_target_nodes(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target_node;
	long		match_idx;

	while (b)
	{
		match_idx = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->data > b->data && curr_a->data < match_idx)
			{
				match_idx = curr_a->data;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match_idx == LONG_MAX)
			b->target_node = search_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	count_moves(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_dblst_size(a);
	size_b = ft_dblst_size(b);
	while (b)
	{
		b->total_moves = b->idx;
		if (b->before_median == false)
			b->total_moves = size_b - (b->idx);
		if (b->target_node->before_median)
			b->total_moves += b->target_node->idx;
		else
			b->total_moves += size_a - (b->target_node->idx);
		b = b->next;
	}
}

void	get_node_least_moves(t_stack_node *b)
{
	long	helper_value;
	t_stack_node	*least_node;

	if (b == NULL)
		return ;
	helper_value = LONG_MAX;
	while (b)
	{
		if (b->total_moves < helper_value)
		{
			helper_value = b->total_moves;
			least_node = b;
		}
		b = b->next;
	}
	least_node->least_moves = true;
}

void	config_nodes(t_stack_node *a, t_stack_node *b)
{
	set_indice(a);
	set_indice(b);
	set_target_nodes(a, b);
	count_moves(a, b);
	get_node_least_moves(b);
}

t_stack_node	*get_least(t_stack_node *stack)
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

void	check_rotate_node(t_stack_node **stack, t_stack_node *top_node, char which_stack)
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

static void	push_swap_nodes(t_stack_node **a, t_stack_node **b)
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

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int	size_a;

	size_a = ft_dblst_size(*a);
	while (size_a-- > 3)
		papb(a, b, "pb");
	sort_three(a);
	while (*b)
	{
		config_nodes(*a, *b);
		push_swap_nodes(a, b);
	}
	set_indice(*a);
	smallest = search_smallest(*a);
	if (smallest->before_median)
		while (*a != smallest)
			rarb(a, "ra");
	else
		while (*a != smallest)
			rrota_ab(a, "rra");
}
