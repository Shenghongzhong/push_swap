/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_dblst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/05 16:33:11 by szhong           ###   ########.fr       */
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

	dup = ft_dblst_new((*stack)->data);
	ft_dblstadd_back(stack, dup);
	ft_dblst_delnode(stack, stack[0]);
	free(dup);
}
