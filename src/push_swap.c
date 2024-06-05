/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 09:26:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

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

void	papb(t_stack_node **src, t_stack_node **dst, char *papb)
{
	dblst_push(src, dst);
	ft_putendl_fd(papb, 1);
}

void	sasb(t_stack_node **stack, char *sasb)
{
	dblst_swap(*stack, (*stack)->next);
	ft_putendl_fd(sasb, 1);
}

void	rarb(t_stack_node **stack, char *rarb)
{
	dblst_rota(stack);
	ft_putendl_fd(rarb, 1);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sasb(a, "sa");
	sasb(b, "sb");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rarb(a, "ra");
	rarb(b, "rb");
}

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
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else
	{
		dblst_stack_init(&a, argc, argv);
		ft_printf("-------before push-------\n");
		ft_printf("a\n");
		print(a);
		ft_printf("b\n");
		papb(&a, &b, "pb");
		print(b);
		ft_printf("----------after push-------\n");
		ft_printf("a\n");
		print(a);
		ft_printf("b\n");
		papb(&a, &b, "pb");
		print(b);
		deallocate(&a);
		deallocate(&b);
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
