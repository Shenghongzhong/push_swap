/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:48:00 by szhong            #+#    #+#             */
/*   Updated: 2024/06/19 11:48:16 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

/**
 * @breif Create and Initialise a new node for an intger.
 *
 * The purpose of the function is to create and initialise value for the node.
 *
 * @param data The element to assign as the list element
 * @return A pointer to the new node or NULL on memory allocation failure
 */
t_stack_node	*ft_dblst_new(int data)
{
	t_stack_node	*db_lst;

	db_lst = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (db_lst == NULL)
		return (NULL);
	db_lst->data = data;
	db_lst->next = NULL;
	db_lst->prev = NULL;
	db_lst->rank = -1;
	return (db_lst);
}

/**
 *  * @breif Add the node to the front of existing nodes.
 *   *
 *    * The function inserts a node before the head node.
 *     *
 *      * @param stack a double pointer to the linked list for modifying the pointer
 *       * @param new a node to insert before the head node
 *        */
void    ft_dblstadd_front(t_stack_node **stack, t_stack_node *new)
{
	if (!new)
		return ;
	if (!stack || !*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * @breif Delete one node from a doubly linked list
 *
 * The function deletes one desired element from the doubly linked list
 *
 * @param top a double pointer for modifying and updating the head node
 * @param del a target node to be deleted from the list
 * @note there are 3 points to focus on. 
 * 1. Deletion of the head node
 * 2. Deletion of the middle node
 * 3. Deletion of the last node
 * three if statement will happen in order
 * 1. Update the head pointer to the second pointer node
 * 2. if it isn't the last pointer then update the prev pointer of the next
 * 3. if it isn't the first pointer then update the next poiner of the prev
 */
void	ft_dblst_delnode(t_stack_node **stack, t_stack_node *del)
{
	if (!*stack || !del)
		return ;
	if (*stack == del)
		*stack = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return ;
}

void	ft_dblstadd_back(t_stack_node **stack, t_stack_node *new_head)
{
	t_stack_node	*old_head;

	if (!new_head || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_head;
		return ;
	}
	old_head = *stack;
	while (old_head->next != NULL)
		old_head = old_head->next;
	old_head->next = new_head;
	new_head->prev = old_head;
	new_head->next = NULL;
	return ;
}
