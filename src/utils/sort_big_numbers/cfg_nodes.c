/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:04 by szhong            #+#    #+#             */
/*   Updated: 2024/07/26 13:55:21 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>
#include "libft.h"

void	config_nodes(t_stack_node *a, t_stack_node *b)
{
	set_indice(a);
	set_indice(b);
	set_target_nodes(a, b);
	count_moves(a, b);
	get_node_least_moves(b);
}

void	set_indice(t_stack_node *a)
{
	int	i;
	int	median;

	i = 0;
	if (a == NULL)
		return ;
	median = ps_dblst_size(a) / 2;
	while (a)
	{
		a->idx = i;
		if (i <= median)
			a->before_median = true;
		else
			a->before_median = false;
		a = a->next;
		i++;
	}
}

void	set_target_nodes(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target_node;
	long			match_idx;

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

	size_a = ps_dblst_size(a);
	size_b = ps_dblst_size(b);
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
	t_stack_node	*least_node;
	long			helper_value;

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
