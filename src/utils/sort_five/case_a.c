/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:29:11 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 14:21:29 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	case_one_odd(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 3)
	{
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (rank == 5)
	{
		papb(b, a, "pa");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	return ;
}

static void	case_one_even(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 2)
	{
		rarb(b, "rb");
		papb(b, a, "pa");
		papb(b, a, "pa");
	}
	else
	{
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	return ;
}

void	case_one(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->next->rank == 2 || t_b->next->rank == 4)
		case_one_even(b, a, t_b->next->rank);
	else if (t_b->next->rank == 5 || t_b->next->rank == 3)
		case_one_odd(b, a, t_b->next->rank);
	return ;
}
