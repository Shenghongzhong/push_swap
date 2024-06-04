/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:30 by szhong            #+#    #+#             */
/*   Updated: 2024/06/04 14:26:53 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	test_print(const char *msg)
{
	ft_printf("%s", msg);
}

void	test_dblst_stack_init()
{
	t_stack_node	*a;
	char	*argv[] = {"57", "48", "72", "88", NULL};

	dblst_stack_init(&a, 4, argv);
	ft_printf("%d\n", a->data);
}

void	tests_run_all(void)
{
	test_dblst_stack_init();
}
