/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:17:06 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/08 21:59:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	do_swap(t_stack *stack, int operation)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	if (operation == SA)
		write(1, "sa\n", 3);
	else if (operation == SB)
		write(1, "sb\n", 3);
	else if (operation == SS)
		write(1, "ss\n", 3);
}

static void	do_push(t_stack *stack_from, t_stack *stack_to, int operation)
{
	int	i;

	if (stack_from->size < 1)
		return ;
	i = stack_to->size;
	while (i > 0)
	{
		stack_to->array[i] = stack_to->array[i - 1];
		i--;
	}
	stack_to->array[0] = stack_from->array[0];
	stack_to->size++;
	i = 0;
	while (i < stack_from->size - 1)
	{
		stack_from->array[i] = stack_from->array[i + 1];
		i++;
	}
	stack_from->size--;
	if (operation == PA)
		write(1, "pa\n", 3);
	else if (operation == PB)
		write(1, "pb\n", 3);
}

static void	do_reverse(t_stack *stack, int operation)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	if (operation == RA)
		write(1, "ra\n", 3);
	else if (operation == RB)
		write(1, "rb\n", 3);
	else if (operation == RR)
		write(1, "rr\n", 3);
}

static void	do_reverse_rotate(t_stack *stack, int operation)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = tmp;
	if (operation == RRA)
		write(1, "rra\n", 4);
	else if (operation == RRB)
		write(1, "rrb\n", 4);
	else if (operation == RRR)
		write(1, "rrr\n", 4);
}

void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation)
{
	static int	process;

	if (operation == SA || operation == SS)
		do_swap(stack_a, SA);
	if (operation == SB || operation == SS)
		do_swap(stack_b, operation);
	if (operation == PA)
		do_push(stack_b, stack_a, PA);
	if (operation == PB)
		do_push(stack_a, stack_b, PB);
	if (operation == RA || operation == RR)
		do_reverse(stack_a, RA);
	if (operation == RB || operation == RR)
		do_reverse(stack_b, operation);
	if (operation == RRA || operation == RRR)
		do_reverse_rotate(stack_a, RRA);
	if (operation == RRB || operation == RRR)
		do_reverse_rotate(stack_b, operation);
	//if (operation == END)
	//	printf("%d\n", process);
	process++;
}
