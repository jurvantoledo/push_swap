/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 14:09:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/19 10:08:10 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	original_position(t_list **stack_a)
{
	int	position;

	position = 0;
	while (*stack_a)
	{
		position++;
		(*stack_a)->position = position;
		stack_a = &(*stack_a)->next;
	}
}

void	bubble_index(t_list **stack)
{
	int	i;

	i = 0;
	while (*stack)
	{
		(*stack)->index = i;
		i++;
		stack = &(*stack)->next;
	}
}

void	bubble_sort(t_list	**stack_a)
{
	t_list	**temp1;
	t_list	*temp2;
	int		swapped;
	int		i;

	swapped = 1;
	i = 0;
	temp2 = NULL;
	while (swapped != 0)
	{
		swapped = 0;
		temp1 = stack_a;
		while ((*temp1)->next != temp2)
		{
			if ((*temp1)->content > (*temp1)->next->content)
			{
				swap(temp1);
				swapped = 1;
			}
			bubble_index(stack_a);
			temp1 = &(*temp1)->next;
		}
		temp2 = *temp1;
	}
}

void	sort_position(t_list **stack_a)
{
	t_list	**ptr1;
	t_list	*temp;
	int		swapped;

	swapped = 1;
	temp = NULL;
	while (swapped != 0)
	{
		swapped = 0;
		ptr1 = stack_a;
		while ((*ptr1)->next != temp)
		{
			if ((*ptr1)->position > (*ptr1)->next->position)
			{
				swap(ptr1);
				swapped = 1;
			}
			ptr1 = &(*ptr1)->next;
		}
		temp = *ptr1;
	}
}
