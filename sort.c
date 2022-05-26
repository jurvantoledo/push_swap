/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 09:58:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/20 16:24:15 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int max_bits, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			pa(stack_b, stack_a);
		i++;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;

	original_position(stack_a);
	bubble_sort(stack_a);
	sort_position(stack_a);
	size = stack_size(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	if (is_sorted(*stack_a))
		return ;
	radix_sort(stack_a, stack_b, max_bits, size);
}
