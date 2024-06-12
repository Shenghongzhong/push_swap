/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:36:53 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:47:58 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_four(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 4 && t_b->next->rank == 1)
	{
		rarb(a, "ra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	else if (t_b->rank == 4 && t_b->next->rank == 2)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if (t_b->rank == 4 && t_b->next->rank == 3)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (t_b->rank == 4 && t_b->next->rank == 5)
	{
		papb(b, a, "pa");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");	
	}
}
