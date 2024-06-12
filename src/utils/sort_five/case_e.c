/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:38:18 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:48:11 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_five(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 5 && t_b->next->rank == 1)
	{
		papb(b, a, "pa");
		rarb(a, "ra");
		papb(b, a, "pa");	
	}
	else if (t_b->rank == 5 && t_b->next->rank == 2)
	{
		rrota_ab(b, "rrb");
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		rarb(a, "ra");	
	}
	else if (t_b->rank == 5 && t_b->next->rank == 3)
	{
		rrr(a, b);
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	else if (t_b->rank == 5 && t_b->next->rank == 4)
	{
		rarb(b, "rb");
		papb(b, a, "pa");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
}
