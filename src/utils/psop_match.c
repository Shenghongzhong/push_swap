/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 13:10:42 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	ss(t_stack_node **a, t_stack_node **b)
{
	sasb(a, "sa");
	sasb(b, "sb");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rarb(a, "ra");
	rarb(b, "rb");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	dblst_rrota(a);
	dblst_rrota(b);
	ft_putendl_fd("rrr", 1);
}
