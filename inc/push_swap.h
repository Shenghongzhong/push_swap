/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:52:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/03 11:15:56 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
typedef struct s_dblst
{
	int	data;
	struct s_dblst	*next;
	struct s_dblst	*prev;
}		t_stack_node;

typedef struct s_stack
{
	unsigned	size;
	int	top;
	int	*arr;
}	t_stack;

t_stack	*create_stack(unsigned);

t_stack_node	*ft_dblst_new(int data);
void	ft_dblstadd_front(t_stack_node **stack, t_stack_node *new_node);
void	stack_init(t_stack **stack, int size, char *argv[]);
int	is_full(t_stack []);
// may removed void	push(t_stack [], int );
void	swap(t_stack []);
size_t	ft_intlcpy(int [], const int [], size_t);
void	rota(t_stack []);
void	rrota(t_stack []);
int	pop(t_stack []);
int	peek(t_stack *stack);
int	is_empty(t_stack *stack);
void	putstack(t_stack *stack);
#endif