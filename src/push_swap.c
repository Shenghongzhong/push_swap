/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 09:26:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char	**arr;

	a = NULL;
	b = NULL;
	arr = handle_args(argv, &argc);
	dblst_stack_init(&a, argc, arr);
	if (argc < 4)
		sort_three(&a);
	else if (argc < 6)
		if (ft_dblst_size(a) == 5)
			sort_five(&a, &b);
/*	else if (argc > 5)
	{
		int	i;
		int	j;

		i 1;
	}*/
	deallocate(&a);
	deallocate(&b);
	return (0);
}
