/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 15:23:50 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/05/20 11:13:37 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	i;
	long	num;
	long	x;

	i = 0;
	num = 0;
	x = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * x);
}
