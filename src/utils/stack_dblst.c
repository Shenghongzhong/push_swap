/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dblst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:54:39 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 13:45:28 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static long	ft_atol(const char *str)
{
	long	num;
	int	sign;
	int	num_sign;

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

void	dblst_stack_init(t_stack_node **a, int size, char *argv[], bool is_argc_2)
{
	int	i;
	long	nbl;
	t_stack_node	*tmp;

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
		tmp = ft_dblst_new((int)nbl);
		ft_dblstadd_back(a, tmp);
		i++;
	}
	if (is_argc_2)
		free_arr(argv);
	rank_stack(a, size - 1);
}
