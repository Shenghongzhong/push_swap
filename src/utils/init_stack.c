/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:54:39 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 19:07:59 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		num_sign;

	num = 0;
	sign = 1;
	num_sign = 0;
	while ((*str > 8 && *str < 14) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		num_sign++;
	}
	if (num_sign > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	dblst_stack_init(t_stack_node **a, char *argv[], \
		bool is_argc_2)
{
	t_stack_node	*tmp;
	long			nbl;
	int				i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, is_argc_2);
		nbl = ft_atol(argv[i]);
		if (nbl > INT_MAX || nbl < INT_MIN)
			error_free(a, argv, is_argc_2);
		if (error_repetition(*a, (int)nbl))
			error_free(a, argv, is_argc_2);
		tmp = ps_dblst_new((int)nbl);
		ps_dblstadd_back(a, tmp);
		i++;
	}
	if (is_argc_2)
		free_arr(argv);
	rank_stack(a, ps_dblst_size(*a));
}

t_stack_node	*tail_node(t_stack_node	*stack)
{
	t_stack_node	*tail;

	tail = stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

void	rank_stack(t_stack_node **stack, int size)
{
	t_stack_node	*node;
	int				*arr;
	int				*ranked_arr;
	int				i;

	i = 0;
	node = *stack;
	arr = (int *)ft_calloc(size, sizeof(int));
	if (arr == NULL)
		return ;
	while (node != NULL)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	i = 0;
	ranked_arr = rank_arr(arr, size);
	node = *stack;
	while (node != NULL && i < size)
	{
		node->rank = ranked_arr[i];
		node = node->next;
		i++;
	}
	free(ranked_arr);
}

int	*rank_arr(int *arr, int n)
{
	int	*arr_to_sort;
	int	i;
	int	j;
	int	k;

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
