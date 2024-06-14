/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:32:19 by szhong            #+#    #+#             */
/*   Updated: 2024/06/14 15:19:40 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	case_two_odd(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 1)
	{
		papb(b, a, "pa");
		papb(b, a, "pa");
	}
	else if (rank == 3)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (rank == 5)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	return ;
}

static void	case_two_even(t_stack_node **b, t_stack_node **a, int rank)
{
	if (rank == 4)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	return ;
}

void	case_two(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->next->rank == 1 || t_b->next->rank == 3 || t_b->next->rank == 5)
		case_two_odd(b, a, t_b->next->rank);
	else if (t_b->next->rank == 4)
		case_two_even(b, a, t_b->next->rank);
	return ;
}
