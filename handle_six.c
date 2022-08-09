/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:39:37 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/08 20:21:17 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	handle_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1])
		do_operation(stack_a, stack_b, SA);
}

void	handle_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[0] == 0 && stack_a->array[1] == 2)
	{
		do_operation(stack_a, stack_b, SA);
		do_operation(stack_a, stack_b, RA);
	}
	else if (stack_a->array[0] == 1 && stack_a->array[1] == 0)
		do_operation(stack_a, stack_b, SA);
	else if (stack_a->array[0] == 1 && stack_a->array[1] == 2)
		do_operation(stack_a, stack_b, RRA);
	else if (stack_a->array[0] == 2 && stack_a->array[1] == 0)
		do_operation(stack_a, stack_b, RA);
	else if (stack_a->array[0] == 2 && stack_a->array[1] == 1)
	{
		do_operation(stack_a, stack_b, SA);
		do_operation(stack_a, stack_b, RRA);
	}
}
