/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:30 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 11:38:06 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	test_print(const char *msg)
{
	ft_printf("%s", msg);
}

void	test_push_empty()
{
	t_stack_node	*top;

	top = NULL;
	push(&top, 21);
	if (top->data == 21 && top->next == NULL )
		test_print("SUCCESS:test_push_empty()\n");
	else
		test_print("FAIL:test_push_empty()\n");
	free(top);
}

void	test_push_non_empty()
{
	t_stack_node	*top;

	top = ft_dblst_new(42);
	push(&top, 21);
	if (top && top->data == 21 && top->next && top->next->data == 42 && top->prev == NULL)
		test_print("SUCCESS:test_push_non_empty()\n");
	else
		test_print("FAIL:test_push_non_empty()\n");

}
void	tests_run_all(void)
{
	test_push_empty();
	test_push_non_empty();
}
