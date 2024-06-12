/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:20:36 by szhong            #+#    #+#             */
/*   Updated: 2024/06/12 20:49:52 by szhong           ###   ########.fr       */
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

void	comp_first_node(t_stack_node **a, t_stack_node **b)
{
	ft_printf("debug--\n");
	if ((*a)->data > (*b)->data)
		papb(b, a, "pa");
	else if (tail_node(*a)->data < (*b)->data)
	{
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	else if ((*a)->data < (*b)->data && (*b)->data < (*a)->next->data)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if ((*a)->data < (*b)->data && (*b)->data > (*a)->next->data)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	else if (tail_node(*a)->data > (*b)->next->data \
			&& (*b)->data > (*a)->next->data)
	{
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		if (handle_edge(a, b, 5) == 1)
			return ;
		rarb(a, "ra");
		rarb(a, "ra");
	}
}

void	comp_second_node(t_stack_node **a, t_stack_node **b)
{
	ft_printf("debug---\n");
	if ((*a)->data > (*b)->data)
		papb(b, a, "pa");
	else if (tail_node(*a)->data < (*b)->data)
	{
		papb(b, a, "pa");
		rarb(a, "ra");
	}
	else if ((*a)->data < (*b)->data && (*a)->next->data > (*b)->data)
	{
		papb(b, a, "pa");
		sasb(a, "sa");
	}
	else if ((*a)->next->data < (*b)->data && tail_node(*a)->prev->data > (*b)->data)
	{
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
	else if (tail_node(*a)->prev->data < (*b)->data)
	{	
		rrota_ab(a, "rra");
		papb(b, a, "pa");
		rarb(a, "ra");
		rarb(a, "ra");
	}
	else
	{
		rarb(a, "ra");
		rarb(a, "ra");
		papb(b, a, "pa");
		rrota_ab(a, "rra");
		rrota_ab(a, "rra");
	}
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*t_b;

	papb(a, b, "pb");
	papb(a, b, "pb");
	sort_three(a);
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
//	comp_first_node(a, b);
//	comp_second_node(a, b);
	return ;
}
