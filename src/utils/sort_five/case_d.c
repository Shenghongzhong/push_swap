/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:36:53 by szhong            #+#    #+#             */
/*   Updated: 2024/06/14 15:31:02 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	case_four_odd(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 1)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
	}
	else if (rank == 3)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (rank == 5)
	{
		papb(b, a, "pa");
		papb(b, a, "pa");
		sasb(a, "sa");
		rarb(a, "ra");
		rarb(a, "ra");	
	}
	return ;
}

static void	case_four_even(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 2)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	return ;
}

void	case_four(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->next->rank == 3 || t_b->next->rank == 1 || t_b->next->rank == 5)
		case_four_odd(b, a, t_b->next->rank);
	else if (t_b->next->rank == 2)
		case_four_even(b, a, t_b->next->rank);
	return ;
}
