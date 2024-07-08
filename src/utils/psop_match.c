/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 14:59:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	ss(t_stack_node **a, t_stack_node **b)
{
	dblst_swap(*a, (*a)->next);
	dblst_swap(*b, (*b)->next);
	ft_putendl_fd("ss", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	dblst_rota(a);
	dblst_rota(b);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	dblst_rrota(a);
	dblst_rrota(b);
	ft_putendl_fd("rrr", 1);
}
