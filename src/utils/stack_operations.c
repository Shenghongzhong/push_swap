/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:20 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 19:04:09 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	dblst_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (*dst == NULL)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
	return ;
}

void	dblst_rota(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = ps_dblst_size(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last_node = tail_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	dblst_rrota(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = ps_dblst_size(*stack);
	if (!*stack || !stack || 1 == len)
		return ;
	last = tail_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	deallocate(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*next;

	if (*stack == NULL)
		return ;
	curr = *stack;
	while (curr->prev != NULL)
		curr = curr->prev;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}
