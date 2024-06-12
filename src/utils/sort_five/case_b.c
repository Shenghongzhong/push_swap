/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:32:19 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:47:35 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_two(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 2 && t_b->next->rank == 1)
	{	
		papb(b, a, "pa");
		papb(b, a, "pa");
	}
	else if (t_b->rank == 2 && t_b->next->rank == 3)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (t_b->rank == 2 && t_b->next->rank == 4)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	else if (t_b->rank == 2 && t_b->next->rank == 5)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
}
