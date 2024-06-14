/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:38:18 by szhong            #+#    #+#             */
/*   Updated: 2024/06/14 15:30:51 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	case_five_odd(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 1)
	{
		papb(b, a, "pa");
		rarb(a, "ra");
		papb(b, a, "pa");	
	}
	else if (rank == 3)
	{
		rrr(a, b);
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	return ;
}

static void	case_five_even(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 2)
	{
		rrota_ab(b, "rrb");
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		rarb(a, "ra");	
	}
	else if (rank == 4)
	{
		rarb(b, "rb");
		papb(b, a, "pa");
		rarb(a, "ra");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	return ;
}
void	case_five(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->next->rank == 3 || t_b->next->rank == 1)
		case_five_odd(b, a, t_b->next->rank);
	else if (t_b->next->rank == 4 || t_b->next->rank == 2)
		case_five_even(b, a, t_b->next->rank);
	return ;
}
