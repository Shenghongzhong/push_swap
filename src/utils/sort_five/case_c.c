/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:34:59 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:47:49 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_three(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 3 && t_b->next->rank == 1)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
	}
	else if (t_b->rank == 3 && t_b->next->rank == 2)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if (t_b->rank == 3 && t_b->next->rank == 4)
	{
		rrr(a, b);
		papb(b, a, "pa");
		papb(b, a, "pa");
		rrota_ab(a, "ra");
		rrota_ab(a, "ra");
	}
	else if (t_b->rank == 3 && t_b->next->rank == 5)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
}
