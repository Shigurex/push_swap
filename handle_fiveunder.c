/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fiveunder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:39:37 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/13 17:55:31 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	handle_two(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	bottom;

	top = stack_a->array[0];
	bottom = stack_a->array[1];
	if (top == bottom + 1)
		do_operation(stack_a, stack_b, SA);
}

static int	min_three(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	handle_three(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	middle;
	int	bottom;
	int	min;

	top = stack_a->array[0];
	middle = stack_a->array[1];
	bottom = stack_a->array[2];
	min = min_three(top, middle, bottom);
	if (top == min && middle == min + 2)
	{
		do_operation(stack_a, stack_b, SA);
		do_operation(stack_a, stack_b, RA);
	}
	else if (top == min + 1 && middle == min)
		do_operation(stack_a, stack_b, SA);
	else if (top == min + 1 && middle == min + 2)
		do_operation(stack_a, stack_b, RRA);
	else if (top == min + 2 && middle == min)
		do_operation(stack_a, stack_b, RA);
	else if (top == min + 2 && middle == min + 1)
	{
		do_operation(stack_a, stack_b, SA);
		do_operation(stack_a, stack_b, RRA);
	}
}

static void	handle_four_five(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (count < size - 3)
	{
		if (stack_a->array[0] < size - 3)
		{
			do_operation(stack_a, stack_b, PB);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RA);
	}
	handle_three(stack_a, stack_b);
	if (size == 4)
		do_operation(stack_a, stack_b, PA);
	if (size == 5)
	{
		if (stack_b->array[0] < stack_b->array[1])
			do_operation(stack_a, stack_b, SB);
		do_operation(stack_a, stack_b, PA);
		do_operation(stack_a, stack_b, PA);
	}
	count = 0;
}

void	handle_fiveunder(int size, t_stack *stack_a, t_stack *stack_b)
{
	if (size == 2)
		handle_two(stack_a, stack_b);
	else if (size == 3)
		handle_three(stack_a, stack_b);
	else
		handle_four_five(size, stack_a, stack_b);
}
