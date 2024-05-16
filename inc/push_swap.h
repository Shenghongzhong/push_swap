/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:52:20 by szhong            #+#    #+#             */
/*   Updated: 2024/05/16 15:47:25 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack
{
	unsigned	size;
	int	top;
	int	*arr;
}	t_stack;

t_stack	*create_stack(unsigned);

int	is_full(t_stack []);
void	push(t_stack [], int );
void	swap(t_stack []);
size_t	ft_intlcpy(int [], const int [], size_t);
void	rota(t_stack []);
void	rrota(t_stack []);

#endif
