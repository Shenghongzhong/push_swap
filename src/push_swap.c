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
	if (!node)
		ft_putendl_fd("node is unitilised", 1);
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

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	//t_stack_node	*b;

	a = NULL;
//	b = NULL;
	if (argc < 2)
		return (1);
	else
	{
		dblst_stack_init(&a, argc, argv);

		rank_stack(&a, argc);
		while (a != NULL)
		{
			ft_printf("rank [%d] - number %d\n", a->rank, a->data);
			a = a->next;
		}
		deallocate(&a);
//		deallocate(&b);
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
