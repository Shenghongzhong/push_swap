/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 09:26:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	print(t_stack_node *node)
{
	while (node->prev != NULL)
		node = node->prev;
	ft_printf("%d\n", node->data);
	while (node->next != NULL)
	{
		node = node->next;
		ft_printf("%d\n", node->data);
	}
	ft_printf("\n");
}

void	sa(t_stack_node **stack, char *sasb)
{
	dblst_swap(*stack, (*stack)->next);
	ft_putendl_fd(sasb, 1);
}
/*
void	rota(t_stack_node **stack)
{
	while ((*stack)->next != NULL)
	{
		stack = stack->next;
	}
}*/

void	deallocate(t_stack_node **stack)
{
	t_stack_node	*curr;

	if (*stack == NULL)
		return ;
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	curr = NULL;
	*stack = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	//t_stack_node	*b;

	a = NULL;
	//b = NULL;
	if (argc < 2)
		return (1);
	else
	{
		dblst_stack_init(&a, argc, argv);
		print(a);
		ft_printf("----------after--------\n");
		print(a);
		deallocate(&a);
	}
}
/*
int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		return (0);
	else
	{
		stack_init(&a, argc, argv);
		ft_putendl_fd("Before", 1);
		putstack(a);
		ft_putendl_fd("After", 1);
		pop(a);
		putstack(a);
	}
}*/
