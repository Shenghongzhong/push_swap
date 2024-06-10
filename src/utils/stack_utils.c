/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:26:43 by szhong            #+#    #+#             */
/*   Updated: 2024/06/10 17:19:49 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_dblst_size(t_stack_node *dblst)
{
	int	count;

	count = 0;
	while (dblst->prev != NULL)
		dblst = dblst->prev;
	while (dblst)
	{
		dblst = dblst->next;
		count++;
	}
	return (count);
}

t_stack_node	*tail_node(t_stack_node	*stack)
{
	t_stack_node	*tail;

	tail = stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}
