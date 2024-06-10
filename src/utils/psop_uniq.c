/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_uniq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/06/10 18:38:01 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	papb(t_stack_node **src, t_stack_node **dst, char *papb)
{
	if (!*src)
		return ;
	while ((*src)->prev != NULL)
		*src = (*src)->prev;
	if ((*dst) != NULL)
		while ((*dst)->prev != NULL)
			*dst = (*dst)->prev;
	dblst_push(src, dst);
	ft_putendl_fd(papb, 1);
}

void	sasb(t_stack_node **stack, char *sasb)
{
	t_stack_node	*head;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	head = *stack;
	dblst_swap(head, head->next);
	ft_putendl_fd(sasb, 1);
}

void	rarb(t_stack_node **stack, char *rarb)
{
	if ((*stack) == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	dblst_rota(stack);
	ft_putendl_fd(rarb, 1);
}

void	rrota_ab(t_stack_node **stack, char *rrab)
{
	if ((*stack) == NULL)
		return ;
	dblst_rrota(stack);
	ft_putendl_fd(rrab, 1);
}
