/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 14:23:32 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/20 13:51:49 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_list	**stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

static void	sort_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a > b && b > c && c < a)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < b && b > c && c < a)
		rra(stack);
	else if (a > b && b < c && c > a)
		sa(stack);
	else if (a > b && b < c && c < a)
		ra(stack);
	else if (a < b && b > c && b > a)
	{
		rra(stack);
		sa(stack);
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int		smallest_number;
	int		position;

	smallest_number = smallest(*stack_a);
	position = lowest_position(*stack_a);
	if (position == 1)
		ra(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	smallest_number;
	int	position;

	smallest_number = smallest(*stack_a);
	position = lowest_position(*stack_a);
	if (position == 1)
		ra(stack_a);
	if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (position == 4)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->arguments == 2)
		sort_2(stack_a);
	else if ((*stack_a)->arguments == 3)
		sort_3(stack_a);
	else if ((*stack_a)->arguments == 4)
		sort_4(stack_a, stack_b);
	else if ((*stack_a)->arguments == 5)
		sort_5(stack_a, stack_b);
}
