/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_dblst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 13:52:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack_node **stack, int item)
{
	t_stack_node	*new_node;
	
	new_node = ft_dblst_new(item);
	ft_dblstadd_front(stack, new_node);
}

int	pop(t_stack_node **stack)
{
	if (!*stack || !stack)
		return (INT_MIN);
	
}
