/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:34:59 by szhong            #+#    #+#             */
/*   Updated: 2024/06/14 15:40:06 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	case_three_odd(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 1)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
	}
	else if (rank == 5)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	return ;
}

static void	case_three_even(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 2)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if (rank == 4)
	{
		rrr(a, b);
		papb(b, a, "pa");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	return ;
}

void	case_three(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->next->rank == 5 || t_b->next->rank == 1)
		case_three_odd(b, a, t_b->next->rank);
	else if (t_b->next->rank == 2 || t_b->next->rank == 4)
		case_three_even(b, a, t_b->next->rank);
	return ;
}
