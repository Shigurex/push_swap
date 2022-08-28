/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sixover_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 19:06:49 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	repeat(t_stack *stack_a, t_stack *stack_b, int operation, int rep)
{
	int	i;

	i = 0;
	while (i < rep)
	{
		do_operation(stack_a, stack_b, operation);
		i++;
	}
}

int	count_roop_num(int size)
{
	int	current_size;
	int	range;
	int	count;

	current_size = size;
	count = 0;
	while (current_size > 10)
	{
		range = current_size / 5 * 3;
		current_size -= range;
		count++;
	}
	return (count);
}

int	*get_separator(int size)
{
	int	mid;
	int	roop;
	int	*separator;
	int	i;

	roop = count_roop_num(size);
	mid = roop + 1;
	separator = malloc(sizeof(int) * (mid * 2 + 1));
	separator[0] = size - 3;
	separator[mid] = size / 3;
	separator[mid * 2] = 0;
	i = 0;
	while (i < roop)
	{
		i++;
		separator[mid - i] = separator[mid - i + 1] + size / 5 * 2;
		separator[mid + i] = separator[mid + i - 1] - size / 5;
		size -= size / 5 * 3;
	}
	return (separator);
}
