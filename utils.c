/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 13:43:47 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/25 13:17:00 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack != NULL)
	{
		if (min > stack->content)
		{
			min = stack->content;
		}
		stack = stack->next;
	}
	return (min);
}

int	lowest_position(t_list *stack)
{
	int	position;
	int	lowest_number;

	position = 0;
	lowest_number = smallest(stack);
	while (lowest_number != stack->content)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	check_int(char *number)
{
	int	i;
	int	j;

	i = 0;
	while (number[i])
	{
		if (((number[i] < '0' || number[i] > '9') && number[i] != '-') || \
			(number[0] == '-' && number[1] == '\0'))
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		j = 1;
		while (number[j])
		{
			if ((number[i] == '-' && number[j] == '-') || \
				(number[i] != '-' && number[j] == '-'))
			{
				write(2, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_duplicates(t_list	*stack)
{
	t_list	*head;
	t_list	*index;

	head = stack;
	if (head == NULL)
		return ;
	while (head)
	{
		index = head->next;
		while (index)
		{
			if (head->content == index->content)
				ft_error(stack, "Error\n", EXIT_FAILURE);
			index = index->next;
		}
		head = head->next;
	}
}
