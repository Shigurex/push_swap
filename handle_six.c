/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:39:37 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/10 18:45:19 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	handle_two(t_stack *stack_a, t_stack *stack_b)
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
