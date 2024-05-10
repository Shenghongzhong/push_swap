/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/05/10 20:40:06 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

typedef struct s_stack
{
	unsigned	size;
	int	top;
	int	*arr;
}	t_stack;

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
	return ((unsigned )stack->top == stack->size - 1);
}

void	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->arr[++stack->top] = item;
}

int	main(int argc, char *argv[])
{
	int	i;
	t_stack	*s;

	if (argc < 2)
		return (0);
	else
	{
		i = 1;
		s = create_stack(argc - 1);
		while (i < argc)
		{
			push(s, ft_atoi(argv[i]));
			i++;
		}
		while (*(s->arr))
		{
			ft_putnbr_fd(*(s->arr), 1);
			s->arr++;
		}
		// sorting algorithm
	}
}
