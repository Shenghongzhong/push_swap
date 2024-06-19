/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:28 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 12:03:07 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	check_argv(char	***arr, char *str)
{
	int	i;

	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
	{
		ft_puterror("Error");
		free_arr(*arr);
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= 48 && str[0] < 58)))
	{
		ft_puterror("Error");
		free_arr(*arr);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] < 58))
		{
			ft_puterror("Error");
			free_arr(*arr);
		}
	}
	str = NULL;
	free_arr(*arr);
	exit(0);
}

char	**handle_args(char **av, int *ac)
{
	char	**arr;
	int		i;

	if (*ac < 2)
		_exit(1);
	else if (*ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr)
			exit(1);
		else if (arr[1] == NULL)
			check_argv(&arr, arr[0]);
		*ac = ft_arr_size(arr);
	}
	else
	{
		i = 0;
		arr = (char **)malloc(*ac * sizeof(char *));
		if (!arr)
			exit(1);
		while (++i < *ac)
			arr[i - 1] = ft_strdup(av[i]);
		arr[i - 1] = NULL;
		*ac -= 1;
	}
	return (arr);
}
