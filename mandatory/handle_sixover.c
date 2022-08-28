/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sixover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 19:13:28 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pb_all(t_stack *stack_a, t_stack *stack_b, int *separator, int roop)
{
	int	count;
	int	range;
	int	i;

	i = 0;
	while (i < roop)
	{
		i++;
		range = stack_a->size / 5 * 3;
		count = 0;
		while (count < range)
		{
			if (separator[roop + 1 + i] <= stack_a->array[0]
				&& stack_a->array[0] < separator[roop + 1 - i])
			{
				do_operation(stack_a, stack_b, PB);
				if (stack_b->array[0] < separator[roop + 1])
					do_operation(stack_a, stack_b, RB);
				count++;
			}
			else
				do_operation(stack_a, stack_b, RA);
		}
	}
}

void	pb_remain(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	mid;
	int	range;

	count = 0;
	mid = size / 3;
	range = stack_a->size - 3;
	while (count < range)
	{
		if (stack_a->array[0] == size - 1 || stack_a->array[0] == size - 2
			|| stack_a->array[0] == size - 3)
			do_operation(stack_a, stack_b, RA);
		else
		{
			do_operation(stack_a, stack_b, PB);
			if (stack_b->array[0] < mid)
				do_operation(stack_a, stack_b, RB);
			count++;
		}
	}
}

void	handle_sixover(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	*separator;
	int	i;
	int	roop;

	separator = get_separator(size);
	roop = count_roop_num(size);
	pb_all(stack_a, stack_b, separator, roop);
	pb_remain(size, stack_a, stack_b);
	handle_three(stack_a, stack_b);
	i = 0;
	while (separator[i] > 0)
	{
		pa_range(separator[i + 1], separator[i], stack_a, stack_b);
		i++;
	}
	free(separator);
}
