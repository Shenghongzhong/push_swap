/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_dblst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 13:30:56 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

void	dblst_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	tmp = ft_dblst_new((*src)->data);
	if (*dst == NULL)
	{
		*dst = tmp;
		ft_dblst_delnode(&(*src), *src);
	}
	else
	{
		ft_dblstadd_front(&(*dst), tmp);
		ft_dblst_delnode(&(*src), *src);
	}
	return ;
}

void	dblst_rota(t_stack_node **stack)
{
	t_stack_node	*dup;

	if (!(*stack))
		return ;
	dup = ft_dblst_new((*stack)->data);
	ft_dblstadd_back(stack, dup);
	ft_dblst_delnode(stack, stack[0]);
	free(dup);
}

void	dblst_rrota(t_stack_node **stack)
{
	t_stack_node	*node;

	if (!(*stack))
		return ;
	node = *stack;
	while (node->next != NULL)
		node = node->next;
	node->prev->next = NULL;
	node->next = *stack;
	(*stack)->prev = node;
	node->prev = NULL;
}

void	deallocate(t_stack_node **stack)
{
	t_stack_node	*curr;

	if (*stack == NULL)
		return ;
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	curr = NULL;
	*stack = NULL;
}
