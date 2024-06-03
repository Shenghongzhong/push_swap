/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:30 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 10:31:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	test_print(const char *msg)
{
	ft_printf("%s", msg);
}

void	test_prev()
{
	void	*nll;
	t_stack_node	*node;

	nll = NULL;
	node = ft_dblst_new(42);
	if (nll != node->prev)
		test_print("FAILED:test_prev()\n");
	else
		test_print("SUCCESS:test_prev()\n");
	free(node);
}

void	test_next()
{
	void	*nll;
	t_stack_node	*node;

	nll = NULL;
	node = ft_dblst_new(42);
	if (nll != node->next)
		test_print("FAILED:test_next()\n");
	else
		test_print("SUCCESS:test_next()\n");
	free(node);
}

void	test_data()
{	
	t_stack_node	*node;

	node = ft_dblst_new(42);
	if (42 != node->data)
		test_print("FAILED:test_data()\n");
	else
		test_print("SUCCESS:test_data()\n");
	free(node);
}

void	tests_run_all(void)
{
	test_prev();
	test_next();
	test_data();
}
