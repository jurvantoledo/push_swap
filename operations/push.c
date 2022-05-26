/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:50:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/20 12:39:30 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = *stack_a;
	if (head == NULL)
		return ;
	*stack_a = head->next;
	head->next = *stack_b;
	*stack_b = head;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}
