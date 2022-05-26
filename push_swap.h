/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:05:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/26 15:13:59 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define PUSH_SWAP_H

typedef struct s_list
{
	int				content;
	int				index;
	int				position;
	int				arguments;
	int				size;
	struct s_list	*next;
}	t_list;

typedef struct s_items {
	int	arguments;
	int	index;
	int	position;
}	t_item;

// Libft
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);

// Push_swap functions
int		smallest(t_list *stack);
int		lowest_position(t_list *stack);
int		stack_size(t_list *stack);
int		is_sorted(t_list *stack);
void	bubble_sort(t_list **stack_a);
void	original_position(t_list **stack_a);
void	sort_position(t_list **stack_a);
void	check_int(char *number);
void	check_duplicates(t_list	*stack);
void	clear_list(t_list *head);
void	ft_error(t_list *stack, char *str, int exit_code);

// Swap list
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// Rotate list
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// Push list
void	push(t_list **stack_pushed, t_list **stack_from);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// Reverse rotate list
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//Sort
void	quick_sort(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);

#endif