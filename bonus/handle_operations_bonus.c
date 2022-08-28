/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:01:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 17:26:22 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

int	read_operation(char *str)
{
	if (str == NULL)
		return (ERR);
	if (!strcmp("sa\n", str))
		return (SA);
	if (!strcmp("sb\n", str))
		return (SB);
	if (!strcmp("ss\n", str))
		return (SS);
	if (!strcmp("pa\n", str))
		return (PA);
	if (!strcmp("pb\n", str))
		return (PB);
	if (!strcmp("ra\n", str))
		return (RA);
	if (!strcmp("rb\n", str))
		return (RB);
	if (!strcmp("rr\n", str))
		return (RR);
	if (!strcmp("rra\n", str))
		return (RRA);
	if (!strcmp("rrb\n", str))
		return (RRB);
	if (!strcmp("rrr\n", str))
		return (RRR);
	return (ERR);
}

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
}
