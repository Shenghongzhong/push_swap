/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:24:23 by szhong            #+#    #+#             */
/*   Updated: 2024/06/27 10:04:44 by szhong           ###   ########.fr       */
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

	if (!arr || *arr == NULL)
		return ;
	i = -1;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr - 1);
}

int	error_syntax(char *nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (*++nbr)
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
	return (0);
}

int	error_repetition(t_stack_node *a, int nb)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->data == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack_node **a, char **argv, bool is_argc_2)
{
	deallocate(a);
	if (is_argc_2)
		free_arr(argv);
	ft_puterror("Error");
	exit(1);
}
