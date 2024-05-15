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

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
}

static size_t	ft_intlcpy(int *dst, const int *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size > 0)
	{
		while (*src && size > 1)
		{
			*dst++ = *src++;
			size--;
			len++;
		}
	}
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}

void	rota(t_stack *stack)
{
	int	*arr;

	arr = (int *)malloc(stack->size * sizeof(int));
	if (arr == NULL)
		return ;
	arr[stack->size- 1] = stack->arr[0];
	ft_memmove(arr, &stack->arr[1], sizeof(int) * (stack->size - 1));
	ft_intlcpy(stack->arr, arr, sizeof(int) * stack->size);
	free(arr);
}

// TODO double check
void	rrota(t_stack *stack)
{
	int	*arr;

	arr = (int *)malloc(stack->size * sizeof(int));
	if (arr == NULL)
		return ;
	arr[0] = stack->arr[stack->size - 1];
	ft_memmove(arr + 1, stack->arr, sizeof(int) * (stack->size - 1));
	ft_intlcpy(stack->arr, arr, sizeof(int) * stack->size);	
	free(arr);
}

void	putstack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->arr[i])
	{
		ft_putnbr_fd(stack->arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
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
		ft_putendl_fd("Before", 1);
		putstack(s);
		ft_putendl_fd("After", 1);
		rrota(s);
		putstack(s);
	}
}
