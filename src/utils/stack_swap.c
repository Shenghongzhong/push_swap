/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:31:09 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 13:34:08 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_neighbour(t_stack_node *a, t_stack_node *b)
{
	return ((a->next == b && b->prev == a) || (a->prev == b && b->next == a));
}

static void	edge_pointer(t_stack_node *a)
{
	if (a->prev != NULL)
		a->prev->next = a;
	if (a->next != NULL)
		a->next->prev = a;
}

static void	swapper_init(t_stack_node **s, t_stack_node **a, t_stack_node **b)
{
	s[0] = (*a)->prev;
	s[1] = (*b)->prev;
	s[2] = (*a)->next;
	s[3] = (*b)->next;
}

static void	matrix_swap(t_stack_node **s, t_stack_node **a, t_stack_node **b)
{
	if (is_neighbour(*a, *b))
	{
		(*a)->prev = s[2];
		(*b)->prev = s[0];
		(*a)->next = s[3];
		(*b)->next = s[1];
	}
	else
	{
		(*a)->prev = s[1];
		(*b)->prev = s[0];
		(*a)->next = s[3];
		(*b)->next = s[2];
	}
}

void	dblst_swap(t_stack_node *a, t_stack_node *b)
{
	if (!a || !b)
		return ;
	t_stack_node	*swapper_vector[4];
	t_stack_node	*tmp;

	if (a == b)
		return ;
	if (b->next == a)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	swapper_init(swapper_vector, &a, &b);
	matrix_swap(swapper_vector, &a, &b);
	edge_pointer(a);
	edge_pointer(b);
}

/*
#include <stdio.h>
void	print(t_stack_node *node)
{
	while (node->prev != NULL)
		node = node->prev;
	printf("   [%d]", node->data);
	while (node->next != NULL)
	{
		node = node->next;
		printf("-[%d]", node->data);
	}
	printf("\n");
}

int	main(void)
{
	t_stack_node	*n1;
	t_stack_node	*n2;
	t_stack_node	*n3;
	t_stack_node	*n4;

	n1 = ft_dblst_new(1);
	n2 = ft_dblst_new(2);
	n3 = ft_dblst_new(3);
	n4 = ft_dblst_new(4);

	ft_dblstadd_front(&n4, n3);
	ft_dblstadd_front(&n4, n2);
	ft_dblstadd_front(&n4, n1);
	printf("\nInitial state:");
	print(n2);

	printf("----------------------\n");
	printf("[1] <-> [2]: ");
	dblst_swap(n1, n2);
	print(n1);

	printf("[2] <-> [1]: ");
	dblst_swap(n2, n1);
	print(n1);

	printf("[1] <-> [3]: ");
	dblst_swap(n1, n3);
	print(n2);

	printf("[3] <-> [1]: ");
	dblst_swap(n1, n3);
	print(n2);

	printf("[3] <-> [1]: ");
	dblst_swap(n3, n1);
	print(n2);

}*/
