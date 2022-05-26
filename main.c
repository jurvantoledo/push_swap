/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:01:09 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/26 15:13:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list *stack, char *str, int exit_code)
{
	clear_list(stack);
	write(2, str, ft_strlen(str));
	exit(exit_code);
}

void	clear_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

void	check_min_max(t_list *stack, char *number)
{
	if (ft_atol(number) > (long)INT_MAX || ft_atol(number) < (long)INT_MIN)
		ft_error(stack, "Error\n", EXIT_FAILURE);
}

t_list	*create_list(char *argv[], int i)
{
	t_list	*list;
	t_list	*head;

	list = ft_calloc(sizeof(t_list), 1);
	if (!list)
		ft_error(0, "Error\n", EXIT_FAILURE);
	head = list;
	while (argv[i])
	{
		if (!list)
			return (NULL);
		check_int(argv[i]);
		list->content = ft_atol(argv[i]);
		check_min_max(list, argv[i]);
		i++;
		if (argv[i])
		{
			list->next = ft_calloc(sizeof(t_list), 1);
			if (!list->next)
				ft_error(list, "Error\n", EXIT_FAILURE);
			list = list->next;
		}
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = create_list(argv, i);
	stack_b = NULL;
	check_duplicates(stack_a);
	if (argc == 1)
		return (0);
	stack_a->arguments = argc - 1;
	if (is_sorted(stack_a))
	{
		clear_list(stack_a);
		exit(EXIT_SUCCESS);
	}
	if (stack_a->arguments <= 5)
		quick_sort(&stack_a, &stack_b);
	else if (stack_a->arguments >= 6)
		big_sort(&stack_a, &stack_b);
	return (0);
}
