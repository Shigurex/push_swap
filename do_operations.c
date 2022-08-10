/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:01:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/10 18:37:36 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	print_operation(int operation)
{
	if (operation == SA)
		write(1, "sa\n", 3);
	else if (operation == SB)
		write(1, "sb\n", 3);
	else if (operation == SS)
		write(1, "ss\n", 3);
	else if (operation == PA)
		write(1, "pa\n", 3);
	else if (operation == PB)
		write(1, "pb\n", 3);
	else if (operation == RA)
		write(1, "ra\n", 3);
	else if (operation == RB)
		write(1, "rb\n", 3);
	else if (operation == RR)
		write(1, "rr\n", 3);
	else if (operation == RRA)
		write(1, "rra\n", 4);
	else if (operation == RRB)
		write(1, "rrb\n", 4);
	else if (operation == RRR)
		write(1, "rrr\n", 4);
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
	print_operation(operation);
	return ;
}

//void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation)
//{
//	int	flag;

//	flag = 0;
//	if (operation == SA || operation == SS)
//		do_swap(stack_a);
//	if (operation == SB || operation == SS)
//		do_swap(stack_b);
//	if (operation == PA)
//		do_push(stack_b, stack_a);
//	if (operation == PB)
//		do_push(stack_a, stack_b);
//	if (operation == RA || operation == RR)
//		do_reverse(stack_a);
//	if (operation == RB || operation == RR)
//		do_reverse(stack_b);
//	if (operation == RRA || operation == RRR)
//		do_reverse_rotate(stack_a);
//	if (operation == RRB || operation == RRR)
//		do_reverse_rotate(stack_b);
//	if (flag == 1)
//	{
//		print_stack(*stack_a, *stack_b);
//		print_operation(operation);
//		usleep(300000);
//	}
//	return ;
//}
