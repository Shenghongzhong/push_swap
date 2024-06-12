/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:29:11 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:47:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_one(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 1 && t_b->next->rank == 2)
	{
		rarb(b, "rb");
		papb(b, a, "pa");
		papb(b, a, "pa");
	}
	else if (t_b->rank == 1 && t_b->next->rank == 3)
	{
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
								}
	else if (t_b->rank == 1 && t_b->next->rank == 4)
	{
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
							}
	else if (t_b->rank == 1 && t_b->next->rank == 5)
	{
		papb(b, a, "pa");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
}
