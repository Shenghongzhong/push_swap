/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:24:23 by szhong            #+#    #+#             */
/*   Updated: 2024/06/17 16:27:07 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_puterror(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	_exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

int	ft_arr_size(char **arr)
{
	int	len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	print(t_stack_node *node, char *signals)
{
	if (!node)
	{
		ft_putendl_fd("node is unitilised", 1);
		return ;
	}
	ft_putendl_fd(signals, 1);
	while (node->prev != NULL)
		node = node->prev;
	while (node->next != NULL)
	{
		node = node->next;
	}
	ft_printf("\n");
}
