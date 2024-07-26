/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:52:20 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 18:43:06 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

// push swap type - doubly linked stack design
typedef struct s_dblst
{
	struct s_dblst		*target_node;
	struct s_dblst		*next;
	struct s_dblst		*prev;
	bool				before_median;
	bool				least_moves;
	int					data;
	int					rank;
	int					idx;
	int					total_moves;
}			t_stack_node;
// push swap doubly linked stack action
int				ps_dblst_size(t_stack_node *dblst);
void			ps_dblstadd_back(t_stack_node **stack, t_stack_node *new_tail);
void			ps_dblstadd_front(t_stack_node **stack, t_stack_node *new_node);
void			ps_dblst_delnode(t_stack_node **stack, t_stack_node *del);
// doubly linked stack 
void			dblst_swap(t_stack_node *a, t_stack_node *n);
void			dblst_rota(t_stack_node **stack);
void			dblst_push(t_stack_node **a, t_stack_node **b);
void			dblst_rrota(t_stack_node **stack);	
void			deallocate(t_stack_node **stack);
void			dblst_stack_init(t_stack_node **a, char *argv[], \
		bool is_argc_2);
// push_swap operations
void			papb(t_stack_node **src, t_stack_node **dst, char *papb);
void			sasb(t_stack_node **stack, char *sasb);
void			rarb(t_stack_node **stack, char *rarb);
void			ss(t_stack_node **a, t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rrota_ab(t_stack_node **stack, char *rrab);
void			rrr(t_stack_node **a, t_stack_node **b);
void			back_to_head(t_stack_node **stack);
// helper function
bool			is_sorted(t_stack_node *a);
char			**ps_split(char const *s, char c);
// sorting 2 or 3
void			sort_tiny(t_stack_node **stack);
void			sort_two(t_stack_node **stack);
void			sort_three(t_stack_node **stack);
void			sort_three_helper(t_stack_node **a);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			rank_stack(t_stack_node **stack, int size);
int				handle_edge(t_stack_node **a, t_stack_node **b, int size);
int				*rank_arr(int *arr, int n);
// sort 4 or 5
void			sort_five(t_stack_node **a, t_stack_node **b);
void			case_one(t_stack_node **b, t_stack_node **a);
void			case_two(t_stack_node **b, t_stack_node **a);
void			case_three(t_stack_node **b, t_stack_node **a);
void			case_four(t_stack_node **b, t_stack_node **a);
void			case_five(t_stack_node **b, t_stack_node **a);
// sorting big numbers (> 5)
void			sort_big(t_stack_node **a, t_stack_node **b);
void			config_nodes(t_stack_node *a, t_stack_node *b);
void			set_indice(t_stack_node *a);
void			set_target_nodes(t_stack_node *a, t_stack_node *b);
void			count_moves(t_stack_node *a, t_stack_node *b);
void			get_node_least_moves(t_stack_node *b);
void			check_rotate_node(t_stack_node **stack, t_stack_node *top_node, \
		char which_stack);
void			push_swap_nodes(t_stack_node **a, t_stack_node **b);
// error handler
void			ft_puterror(char *err_msg);
void			free_arr(char **arr);
void			error_free(t_stack_node **a, char **argv, bool is_argc_2);
int				error_syntax(char *nbr);
int				error_repetition(t_stack_node *a, int nb);

t_stack_node	*ps_dblst_new(int data);
t_stack_node	*tail_node(t_stack_node	*stack);
t_stack_node	*search_smallest(t_stack_node *stack);
#endif
