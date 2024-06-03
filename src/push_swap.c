/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:49 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 09:26:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

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
}
