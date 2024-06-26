/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:47:37 by szhong            #+#    #+#             */
/*   Updated: 2024/06/21 10:30:21 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	dblst_stack_init(&a, argc, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (argc - 1 < 4)
			sort_tiny(&a);
		else if (argc - 1 < 6)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	deallocate(&a);
	deallocate(&b);
	return (0);
}
