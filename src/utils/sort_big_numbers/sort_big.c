/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:04 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 18:15:30 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>
#include "libft.h"

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

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				size_a;

	size_a = ps_dblst_size(*a);
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
