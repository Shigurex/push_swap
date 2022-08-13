/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:01:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/13 17:59:30 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation)
{
	if (operation == SA || operation == SS)
		do_swap(stack_a);
	if (operation == SB || operation == SS)
		do_swap(stack_b);
	if (operation == PA)
		do_push(stack_b, stack_a);
	if (operation == PB)
		do_push(stack_a, stack_b);
	if (operation == RA || operation == RR)
		do_reverse(stack_a);
	if (operation == RB || operation == RR)
		do_reverse(stack_b);
	if (operation == RRA || operation == RRR)
		do_reverse_rotate(stack_a);
	if (operation == RRB || operation == RRR)
		do_reverse_rotate(stack_b);
	stack_operation(operation);
}
