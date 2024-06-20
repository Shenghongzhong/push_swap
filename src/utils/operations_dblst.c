/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_dblst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 18:46:13 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	dblst_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	tmp = ft_dblst_new((*src)->data);
	tmp->rank = (*src)->rank;
	if (*dst == NULL)
		*dst = tmp;
	else
		ft_dblstadd_front(&(*dst), tmp);
	ft_dblst_delnode(&(*src), *src);
	return ;
}

void	dblst_rota(t_stack_node **stack)
{
	t_stack_node	*dup;

	if (!(*stack) || !((*stack)->next))
		return ;
	while ((*stack)->prev != NULL)
		(*stack) = (*stack)->prev;
	dup = ft_dblst_new((*stack)->data);
	dup->rank = (*stack)->rank;
	ft_dblstadd_back(stack, dup);
	ft_dblst_delnode(stack, *stack);
}

void	dblst_rrota(t_stack_node **stack)
{
	t_stack_node	*node;

	if (!(*stack) || !((*stack)->next))
		return ;
	while ((*stack)->prev != NULL)
		(*stack) = (*stack)->prev;
	node = *stack;
	while (node->next != NULL)
		node = node->next;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
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
