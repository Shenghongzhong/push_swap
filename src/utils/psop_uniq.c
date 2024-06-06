/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_uniq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 13:35:42 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	papb(t_stack_node **src, t_stack_node **dst, char *papb)
{
	dblst_push(src, dst);
	ft_putendl_fd(papb, 1);
}

void	sasb(t_stack_node **stack, char *sasb)
{
	if ((*stack) == NULL)
		return ;
	dblst_swap(*stack, (*stack)->next);
	ft_putendl_fd(sasb, 1);
}

void	rarb(t_stack_node **stack, char *rarb)
{
	if ((*stack) == NULL)
		return ;
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
