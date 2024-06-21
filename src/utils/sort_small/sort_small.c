/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:20:36 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 10:16:01 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

int	handle_edge(t_stack_node **a, t_stack_node **b, int size)
{
	if (size == 5)
	{
		if ((*b)->data < (*a)->data \
				&& (*b)->data > tail_node(*a)->data)
		{
			papb(b, a, "pa");
			rrota_ab(a, "rra");
			rrota_ab(a, "rra");
			return (1);
		}
	}
	return (0);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 1)
		papb(b, a, "pa");
	else if (t_b->rank == 2)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if (t_b->rank == 3)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	else if (t_b->rank == 4)
	{
		papb(b, a, "pa");
		rarb(a, "ra");
	}
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*t_b;

	t_b = *b;
	if (t_b->rank == 1)
		case_one(b, a);
	else if (t_b->rank == 2)
		case_two(b, a);
	else if (t_b->rank == 3)
		case_three(b, a);
	else if (t_b->rank == 4)
		case_four(b, a);
	else
		case_five(b, a);
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	while (ft_dblst_size(*a) > 3)
		papb(a, b, "pb");
	sort_three(a);
	if (ft_dblst_size(*b) == 1)
		sort_four(a, b);
	else
		sort_five(a, b);
	return ;
}
