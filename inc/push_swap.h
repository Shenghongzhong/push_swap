/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:52:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/06 14:27:53 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
typedef struct s_dblst
{
	int	*data;
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
void	ft_dblstadd_back(t_stack_node *[], t_stack_node *);
void	ft_dblst_delnode(t_stack_node *[], t_stack_node *);
void	deallocate(t_stack_node **stack);

void	dblst_stack_init(t_stack_node **a, t_stack_node **b, int size, char *argv[]);
void	dblst_swap(t_stack_node *a, t_stack_node *n);
void	dblst_rota(t_stack_node **stack);
void	dblst_push(t_stack_node **a, t_stack_node **b);
void	dblst_rrota(t_stack_node **stack);	
int	check_stack(t_stack_node **stack);

void	papb(t_stack_node **src, t_stack_node **dst, char *papb);
void	sasb(t_stack_node **stack, char *sasb);
void	rarb(t_stack_node **stack, char *rarb);
void	ss(t_stack_node **a, t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rrota_ab(t_stack_node **stack, char *rrab);
void	rrr(t_stack_node **a, t_stack_node **b);


void	stack_init(t_stack **stack, int size, char *argv[]);
int	is_full(t_stack []);
void	push(t_stack [], int );
void	swap(t_stack []);
size_t	ft_intlcpy(int [], const int [], size_t);
void	rota(t_stack []);
void	rrota(t_stack []);
int	pop(t_stack []);
int	peek(t_stack *stack);
int	is_empty(t_stack *stack);
void	putstack(t_stack *stack);
#endif
