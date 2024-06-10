/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:39:01 by szhong            #+#    #+#             */
/*   Updated: 2024/06/10 09:27:52 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	rank_stack(t_stack_node **stack, int size)
{
	t_stack_node	*node;
	int	*arr;
	int	*ranked_arr;
	int	i;

	i = 0;
	node = *stack;
	arr = (int *)ft_calloc(size - 1, sizeof(int));
	if (arr == NULL)
		return ;
	while (node != NULL)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	i = 0;
	ranked_arr = rank_arr(arr, size - 1);
	node = *stack;
	while (node != NULL && i < size - 1)
	{
		node->rank = ranked_arr[i];
		node = node->next;
		i++;
	}
	free(ranked_arr);
}

int	*rank_arr(int *arr, int n) 
{ 
	int *arr_to_sort;
	int i;
	int j;
	int k;

	i = 0;
	arr_to_sort = ft_calloc(n, sizeof (int));
	if (!arr_to_sort)
		return (NULL);
	while (i < n)
	{
		k = 0;
		j = 0;
		while (j < n)
		{
			if (arr[i] >= arr[j])
				k += 1;
			++j;
		}
		arr_to_sort[i] = k;
		i++;
	}
	free(arr);
	return (arr_to_sort);
}
