/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:48:00 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 15:26:12 by szhong           ###   ########.fr       */
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
t_stack_node	*ps_dblst_new(int data)
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
void	ps_dblst_delnode(t_stack_node **stack, t_stack_node *del)
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

/**
 * @breif Append a node to the doubly linked list 
 *
 * add a node to the end of the doubly linked list
 * @param stack a pointer to the head 
 * @param new_tail a pointer to the node to append
 * @return a new doubly linked list
 *
 */
void	ps_dblstadd_back(t_stack_node **stack, t_stack_node *new_tail)
{
	t_stack_node	*dblst;

	if (!new_tail || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_tail;
		return ;
	}
	dblst = *stack;
	while (dblst->next != NULL)
		dblst = dblst->next;
	dblst->next = new_tail;
	new_tail->prev = dblst;
	new_tail->next = NULL;
	return ;
}

/**
* @breif Add the node to the front of existing nodes.
*
* The function inserts a node before the head node.
*
* @param stack a double pointer to the linked list for modifying the pointer
* @param new a node to insert before the head node
**/
void	ps_dblstadd_front(t_stack_node **stack, t_stack_node *new_node)
{
	if (!new_node)
		return ;
	if (!stack || !*stack)
	{
		*stack = new_node;
		return ;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * @breif Count the total number of nodes in doubly linked list
 *
 * The function calculates the number of nodes in the list
 *
 * @param dblst a pointer to a node in the list
 * @return an integer for the number of nodes in the list
 */
int	ps_dblst_size(t_stack_node *dblst)
{
	int	count;

	if (dblst == NULL)
		return (1);
	count = 0;
	while (dblst)
	{
		dblst = dblst->next;
		count++;
	}
	return (count);
}
