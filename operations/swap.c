/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 11:09:38 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/18 15:25:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*head;

	head = (*stack)->next;
	(*stack)->next = head->next;
	head->next = (*stack);
	(*stack) = head;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
