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

void	ft_puterror(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	_exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

int	ft_arr_size(char **arr)
{
	int	len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	check_argv(char	***arr, char *str)
{
	int	i;

	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
	{
		ft_puterror("Unvalid argument input: No valid number");
		free_arr(*arr);
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= 48 && str[0] < 58)))
	{
		ft_puterror("Unvalid arument input: No valid number");
		free_arr(*arr);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] < 58))
		{
			ft_puterror("Unvalid arument input: No valid number");
			free_arr(*arr);
		}
	}
	str = NULL;
	free_arr(*arr);
	exit(0);
}

char	**handle_args(char **av, int *ac)
{
	char	**arr;
	int		i;

	if (*ac < 2)
		_exit(1);
	else if (*ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr)
			exit(1);
		else if (arr[1] == NULL)
			check_argv(&arr, arr[0]);
		*ac = ft_arr_size(arr);
	}
	else
	{
		i = 0;
		arr = (char **)malloc(*ac * sizeof(char *));
		if (!arr)
			exit(1);
		while (++i < *ac)
			arr[i - 1] = ft_strdup(av[i]);
		arr[i - 1] = NULL;
		*ac -= 1;
	}
	return (arr);
}

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
	{
//		print(a, "a");
		if (ft_dblst_size(a) == 5)
			sort_five(&a, &b);
	//	print(a, "a");
	}
	deallocate(&a);
	deallocate(&b);
	return (0);
}
