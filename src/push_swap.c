/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 09:26:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

void	print(t_stack_node *node, char *signals)
{
	if (!node)
	{
		ft_putendl_fd("node is unitilised", 1);
		return ;
	}
	ft_putendl_fd(signals, 1);
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
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	
	dblst_stack_init(&a, argc, argv);
	if (argc <= 4)
		sort_three(&a);
	else if (argc <= 6)
	{
		if (ft_dblst_size(a) == 5)
		{
			print(a, "before \n a");
			papb(&a, &b, "pb");
			papb(&a, &b, "pb");
			sort_three(&a);
			if (a->data > b->data)
				papb(&b, &a, "pa");
			else if (tail_node(a)->data < b->data)
			{
				papb(&b, &a, "pa");
				rarb(&a, "ra");
			}
			else if(a->data > b->data \
					&& b->data < a->next->data)
			{
				papb(&b, &a, "pa");
				sasb(&a, "sa");
			}
			else if (tail_node(a)->data > b->data \
					&& b->data > a->next->data)
			{
				rrota_ab(&a, "rra");
				papb(&b, &a, "pa");
				if (b->data < a->data \
						&& b->data > tail_node(a)->data)
				{
					papb(&b, &a, "pa");
					rrota_ab(&a, "rra");
					rrota_ab(&a, "rra");
					print(a,"complete a ");
					return (0);
				}
				else
				{
					rarb(&a, "ra");
					rarb(&a, "ra");
				}
			}
			else if (a->data < b->data && a->next->data > b->data)
			{
				papb(&b, &a, "pa");
				sasb(&a,"sa");
			}

			// for the last one in stack b
			ft_printf("last one\n");
			if (a->data > b->data)
				papb(&b, &a, "pa");
			else if (tail_node(a)->data < b->data)
			{
				papb(&b, &a, "pa");
				rarb(&a, "ra");
			}
			else if (b->data > a->data && b->data < a->next->data)
			{
				papb(&b, &a, "pa");
				sasb(&a, "sa");
			}
			else if (b->data > a->next->data && b->data < tail_node(a)->prev->data)
			{
				rarb(&a, "ra");
				rarb(&a, "ra");
				papb(&b, &a, "pa");
				rrota_ab(&a, "rra");
				rrota_ab(&a, "rra");
			}
			else if (b->data > tail_node(a)->prev->data \
					&& b->data <tail_node(a)->data)
			{	
				rrota_ab(&a, "rra");
				papb(&b, &a, "pa");
				rarb(&a, "ra");
				rarb(&a, "ra");
			}
		}
		print(a, "a");
		print(b, "b");
	}
	deallocate(&a);
	deallocate(&b);
}
