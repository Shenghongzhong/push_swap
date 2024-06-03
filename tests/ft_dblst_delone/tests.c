/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:30 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 15:33:59 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	test_print(const char *msg)
{
	ft_printf("%s", msg);
}

void	del(int *data)
{
	free(data);
}

void	test_delone()
{
	t_stack_node	*top;
	t_stack_node	*next;

	top = ft_dblst_new(42);
	next = ft_dblst_new(21);
	ft_dblstadd_front(&top, next);
	if (top->data == 21)
		ft_printf("the value is 21, 42");
	ft_dblst_delone(&top, del);

	//if (top->data == 42 && top->next->prev == top && top->next == NULL)
	//	test_print("SUCCESS:test_delone()\n");
	//else
	//	test_print("FAIL:test_delone())\n");
}

void	tests_run_all(void)
{
	test_delone();
}
