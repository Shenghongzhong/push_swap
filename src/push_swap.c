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

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	dblst_stack_init(&a, argc, argv + 1, argc == 2);
	if (argc - 1 < 4)
		sort_three(&a);
	else if (argc- 1 < 6)
		if (ft_dblst_size(a) == 5)
			sort_five(&a, &b);
	deallocate(&a);
	deallocate(&b);
	return (0);
}
