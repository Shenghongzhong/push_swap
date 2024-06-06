/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_uniq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 14:27:18 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	papb(t_stack_node **src, t_stack_node **dst, char *papb)
{
	if (!(*src) && !(*dst))
		return ;
	dblst_push(src, dst);
	ft_putendl_fd(papb, 1);
}

void	sasb(t_stack_node **stack, char *sasb)
{
	if (check_stack(stack) == -1)
		return ;
	dblst_swap(*stack, (*stack)->next);
	ft_putendl_fd(sasb, 1);
}

void	rarb(t_stack_node **stack, char *rarb)
{
	if (check_stack(stack) == -1)
		return ;
	dblst_rota(stack);
	ft_putendl_fd(rarb, 1);
}

void	rrota_ab(t_stack_node **stack, char *rrab)
{
	if (check_stack(stack) == -1)
		return ;
	dblst_rrota(stack);
	ft_putendl_fd(rrab, 1);
}
