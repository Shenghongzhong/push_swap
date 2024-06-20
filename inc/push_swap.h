/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:52:20 by szhong            #+#    #+#             */
/*   Updated: 2024/06/20 13:56:04 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_dblst
{
	int	data;
	int	rank;
	bool	before_median;
	bool	least_moves;
	int	idx;
	int	total_moves;
	struct s_dblst	*target_node;
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

bool	is_sorted(t_stack_node *a);
t_stack_node	*ft_dblst_new(int data);
void	ft_dblstadd_front(t_stack_node **stack, t_stack_node *new_node);
void	ft_dblstadd_back(t_stack_node *[], t_stack_node *);
void	ft_dblst_delnode(t_stack_node *[], t_stack_node *);

void	dblst_stack_init(t_stack_node **a, int size, char *argv[], bool is_argc_2);
void	dblst_swap(t_stack_node *a, t_stack_node *n);
void	dblst_rota(t_stack_node **stack);
void	dblst_push(t_stack_node **a, t_stack_node **b);
void	dblst_rrota(t_stack_node **stack);	
void	deallocate(t_stack_node **stack);

void	papb(t_stack_node **src, t_stack_node **dst, char *papb);
void	sasb(t_stack_node **stack, char *sasb);
void	rarb(t_stack_node **stack, char *rarb);
void	ss(t_stack_node **a, t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rrota_ab(t_stack_node **stack, char *rrab);
void	rrr(t_stack_node **a, t_stack_node **b);

int	ft_dblst_size(t_stack_node *dblst);


void	rank_stack(t_stack_node **stack, int size);
int	*rank_arr(int *arr, int n);

// to be deleted
void	comp_first_node(t_stack_node **a, t_stack_node **b);
void	comp_second_node(t_stack_node **a, t_stack_node **b);
// =============

t_stack_node	*tail_node(t_stack_node	*stack);

void	papb(t_stack_node **src, t_stack_node **dst, char *papb);
void	sasb(t_stack_node **stack, char *sasb);
void	rarb(t_stack_node **stack, char *rarb);
void	rrota_ab(t_stack_node **stack, char *rrab);
void	ss(t_stack_node **a, t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

// sorting small numbers
void	sort_three(t_stack_node **stack);
void	sort_five(t_stack_node **a, t_stack_node **b);
int	handle_edge(t_stack_node **a, t_stack_node **b, int size);
void	case_one(t_stack_node **b, t_stack_node **a);
void	case_two(t_stack_node **b, t_stack_node **a);
void	case_three(t_stack_node **b, t_stack_node **a);
void	case_four(t_stack_node **b, t_stack_node **a);
void	case_five(t_stack_node **b, t_stack_node **a);


// sorting big numbers
void	sort_big(t_stack_node *[], t_stack_node *[]);
// valid input check
void	check_argv(char	***arr, char *str);
char	**handle_args(char **av, int *ac);

// error handler
void	ft_puterror(char *err_msg);
void	free_arr(char **arr);
int	ft_arr_size(char **arr);
void	print(t_stack_node *node, char *signals);
int	error_syntax(char *nbr);
int	error_repetition(t_stack_node *a, int nb);
void	error_free(t_stack_node **a, char **argv, bool is_argc_2);


// array method
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
