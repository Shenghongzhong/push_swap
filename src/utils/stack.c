/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/05/20 17:55:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	stack_init(t_stack **stack, int size, char *argv[])
{
	int	i;

	i = 1;
	*stack = create_stack((unsigned int) size - 1);
	while (i < size)
	{
		push(*stack, ft_atoi(argv[i]));
		i++;
	}
	return ;
}

t_stack	*create_stack(unsigned size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (0);
	stack->top = -1;
	stack->size = size;
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (stack->arr == NULL)
		return (0);
	return (stack);
}

int	is_full(t_stack *stack)
{
	if ((unsigned )stack->top == stack->size - 1)
		return (1);
	return (0);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

void	putstack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		ft_putnbr_fd(stack->arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
