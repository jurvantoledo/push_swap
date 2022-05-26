/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 11:18:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/19 13:11:57 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	rotate(t_list **stack)
// {
// 	t_list	*head;
// 	t_list	*first;

// 	first = *stack;
// 	head = (*stack)->next;
// 	(*stack)->next = NULL;
// 	*stack = head;
// 	ft_lstadd_back(stack, first);
// }

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*first;

	first = *stack;
	head = (*stack)->next;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = first;
	first->next = NULL;
	(*stack) = head;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
