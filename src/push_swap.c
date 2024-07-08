/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:47:37 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 15:42:05 by szhong           ###   ########.fr       */
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
		argv = ps_split(argv[1], ' ');
	dblst_stack_init(&a, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (ps_dblst_size(a) < 4)
			sort_tiny(&a);
		else if (ps_dblst_size(a) > 3 && ps_dblst_size(a) < 6)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	deallocate(&a);
	if (b != NULL)
		deallocate(&b);
	return (0);
}
