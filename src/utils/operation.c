/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:27 by szhong            #+#    #+#             */
/*   Updated: 2024/05/16 15:45:38 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

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

size_t	ft_intlcpy(int *dst, const int *src, size_t size)
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
