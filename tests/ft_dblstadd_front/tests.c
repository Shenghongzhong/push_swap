/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:57:30 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 10:46:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	test_print(const char *msg)
{
	ft_printf("%s", msg);
}

void	test_empty_lst()
{
	t_stack_node	*stack = NULL;
	t_stack_node	*new_node = ft_dblst_new(42);

	ft_dblstadd_front(&stack, new_node);
	if (stack == new_node && stack->next == NULL && stack->prev == NULL)
		test_print("FAILED:test_empty_lst()\n");
	else
		test_print("SUCCESS:test_empty_lst()\n");
	free(new_node);
}

void	test_non_empty_list()
{
	t_stack_node	*stack = ft_dblst_new(10);
	t_stack_node	*new_node = ft_dblst_new(20);

	ft_dblstadd_front(&stack, new_node);
	if (stack == new_node && stack->data == 20 && stack->next->data == 10 && stack->prev == NULL && stack->next->prev == stack)
		test_print("FAILED:test_non_empty_list()\n");
	else
		test_print("SUCCESS:test_non_empty_list()\n");
	free(stack->next);
	free(stack);
}

void test_ft_dblstadd_front_null_stack(void)
{
    t_stack_node *new_node = ft_dblst_new(42);

    ft_dblstadd_front(NULL, new_node);

    if (new_node->next == NULL && new_node->prev == NULL)
        test_print("SUCCESS: test_ft_dblstadd_front_null_stack()\n");
    else
        test_print("FAILED: test_ft_dblstadd_front_null_stack()\n");

    free(new_node);
}

void	tests_run_all(void)
{
	test_ft_dblstadd_front_null_stack();
	test_non_empty_list();
	test_empty_lst();
}
