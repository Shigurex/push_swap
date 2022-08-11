/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oversix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 13:15:28 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pb_all(int mid, int max, t_stack *stack_a, t_stack *stack_b);

int	rotate_sorted(int size, t_stack *stack_a, t_stack *stack_b)
{
	if (size == 1)
		do_operation(stack_a, stack_b, RA);
	else if (size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
			do_operation(stack_a, stack_b, SA);
		do_operation(stack_a, stack_b, RA);
		do_operation(stack_a, stack_b, RA);
	}
	return (0);
}

void	pa_all(int mid, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	size;
	int	count;

	min = stack_a->array[stack_a->size - 1] + 1;
	size = max - min;
	count = 0;
	while (count < size)
	{
		if (stack_b->array[0] == min && stack_b->size > 1)
		{
			do_operation(stack_a, stack_b, PA);
			do_operation(stack_a, stack_b, RA);
			min++;
		}
		else
			do_operation(stack_a, stack_b, PA);
		count++;
	}
	pb_all((min + mid) / 2, mid, stack_a, stack_b);
	pb_all((mid + max) / 2, max, stack_a, stack_b);
}

void	pb_all(int mid, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	size;
	int	count;

	min = stack_a->array[stack_a->size - 1] + 1;
	size = max - min;
	if (size <= 2)
	{
		rotate_sorted(size, stack_a, stack_b);
		return ;
	}
	count = 0;
	while (count < size)
	{
		if (stack_a->array[0] == min)
		{
			do_operation(stack_a, stack_b, RA);
			min++;
		}
		else
		{
			do_operation(stack_a, stack_b, PB);
			if (stack_b->array[0] < mid && stack_b->size > 1)
				do_operation(stack_a, stack_b, RB);
		}
		count++;
	}
	pa_all(mid, max, stack_a, stack_b);
}

void	initial_pa_all(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	min;

	count = 0;
	min = 0;
	while (count < size)
	{
		if (stack_b->array[0] == min)
		{
			do_operation(stack_a, stack_b, PA);
			do_operation(stack_a, stack_b, RA);
			min++;
		}
		else
			do_operation(stack_a, stack_b, PA);
		count++;
	}
}

void	initial_pb_half(int quarter, int mid, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (count < mid)
	{
		if (stack_a->array[0] < mid)
		{
			do_operation(stack_a, stack_b, PB);
			if (stack_b->array[0] < quarter && stack_b->size > 1)
				do_operation(stack_a, stack_b, RB);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RA);
	}
}

void	quicksort(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	quarter;

	mid = size / 2;
	quarter = mid / 2;
	initial_pb_half(quarter, mid, stack_a, stack_b);
	initial_pa_all(mid, stack_a, stack_b);
	pb_all(quarter / 2, quarter, stack_a, stack_b);
	pb_all((quarter + mid) / 2, mid, stack_a, stack_b);
	pb_all((mid + size) / 2, size, stack_a, stack_b);
}
