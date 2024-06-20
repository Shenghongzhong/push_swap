/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:57:40 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 13:54:00 by szhong           ###   ########.fr       */
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

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*a;

	if (!*stack)
		return ;
	a = *stack;
	if (a->data > a->next->data && (a->next->data > a->next->next->data))
	{
		rrota_ab(&a, "rra");
		rrota_ab(&a, "rra");
		sasb(&a, "sa");
	}
	else if (a->data < a->next->data && (a->data > a->next->next->data))
		rrota_ab(&a, "rra");
	else if (a->data > a->next->data && (a->data < a->next->next->data))
		sasb(&a, "sa");
	else if (a->next->data > a->next->next->data && (a->data < a->next->next->data))
	{
		rrota_ab(&a, "rra");
		sasb(&a, "sa");
	}
	else if (a->data > a->next->data && (a->next->data < a->next->next->data))
	{
		rrota_ab(&a, "rra");
		rrota_ab(&a, "rra");
	}
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
}
