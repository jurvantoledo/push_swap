/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 14:46:55 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/13 11:28:16 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*head;

	if ((*stack)->next == NULL)
		return ;
	head = *stack;
	while (head->next->next != NULL)
		head = head->next;
	last = head->next;
	last->next = *stack;
	*stack = last;
	head->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
