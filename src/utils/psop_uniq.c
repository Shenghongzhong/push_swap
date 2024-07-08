/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_uniq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 18:45:46 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	back_to_head(t_stack_node **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
}

void	papb(t_stack_node **src, t_stack_node **dst, char *papb)
{
	if (!*src)
		return ;
	back_to_head(src);
	if ((*dst) != NULL)
		back_to_head(dst);
	dblst_push(src, dst);
	ft_putendl_fd(papb, 1);
}

void	sasb(t_stack_node **stack, char *sasb)
{
	t_stack_node	*head;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	back_to_head(stack);
	head = *stack;
	dblst_swap(head, head->next);
	ft_putendl_fd(sasb, 1);
	if ((*stack) != NULL)
		back_to_head(stack);
}

void	rarb(t_stack_node **stack, char *rarb)
{
	if ((*stack) == NULL || (*stack)->next == NULL )
		return ;
	back_to_head(stack);
	dblst_rota(stack);
	back_to_head(stack);
	ft_putendl_fd(rarb, 1);
}

void	rrota_ab(t_stack_node **stack, char *rrab)
{
	if ((*stack) == NULL || (*stack)->next == NULL )
		return ;
	dblst_rrota(stack);
	ft_putendl_fd(rrab, 1);
}
