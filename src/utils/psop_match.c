/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psop_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:03:10 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 14:44:09 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (check_stack(a) == -1 || check_stack(b) == -1)
		return ;
	sasb(a, "sa");
	sasb(b, "sb");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (check_stack(a) == -1 || check_stack(b) == -1)
		return ;
	rarb(a, "ra");
	rarb(b, "rb");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (check_stack(a) == -1 || check_stack(b) == -1)
		return ;
	dblst_rrota(a);
	dblst_rrota(b);
	ft_putendl_fd("rrr", 1);
}
