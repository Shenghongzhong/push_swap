/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:57:40 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 16:19:05 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdbool.h>

bool	is_sorted(t_stack_node *a)
{
	if (NULL == a)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

void	sort_two(t_stack_node **stack)
{
	t_stack_node	*a;

	a = *stack;
	if (a->data > a->next->data)
		sasb(&a, "sa");
	return ;
}

void	sort_three(t_stack_node **a)
{
	if (!*a)
		return ;
	sort_three_helper(a);
	while ((*a)->prev != NULL)
		*a = (*a)->prev;
}

void	sort_three_helper(t_stack_node **a)
{
	if ((*a)->data > (*a)->next->data && \
			((*a)->next->data > (*a)->next->next->data))
	{
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		sasb(a, "sa");
	}
	else if ((*a)->data < (*a)->next->data && \
			((*a)->data > (*a)->next->next->data))
		rrota_ab(a, "rra");
	else if ((*a)->data > (*a)->next->data && \
			((*a)->data < (*a)->next->next->data))
		sasb(a, "sa");
	else if ((*a)->next->data > (*a)->next->next->data && \
			((*a)->data < (*a)->next->next->data))
	{
		rrota_ab(a, "rra");
		sasb(a, "sa");
	}
	else if ((*a)->data > (*a)->next->data && \
			((*a)->next->data < (*a)->next->next->data))
	{
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
}

void	sort_tiny(t_stack_node **stack)
{
	if (!stack || !*stack)
		return ;
	if (ps_dblst_size(*stack) == 2)
		sort_two(stack);
	else if (ps_dblst_size(*stack) == 3)
		sort_three(stack);
	return ;
}
