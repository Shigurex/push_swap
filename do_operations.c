/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:01:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 16:59:37 by yahokari         ###   ########.fr       */
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

void	check_pa_pb(int *operations, int *size, int cur)
{
	if (cur < *size - 1 && ((operations[cur] == PA && operations[cur + 1] == PB)
			|| (operations[cur] == PB && operations[cur + 1] == PA)))
	{
		*size -= 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 2];
			cur++;
		}
	}
}

void	check_ra_rb(int *operations, int *size, int cur)
{
	if (cur < *size - 1 && ((operations[cur] == RA && operations[cur + 1] == RB)
			|| (operations[cur] == RB && operations[cur + 1] == RA)))
	{
		*size -= 1;
		operations[cur] = RR;
		cur++;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_pb_ra_pa(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == PB && operations[cur + 1] == RA
			&& operations[cur + 2] == PA))
	{
		*size -= 1;
		operations[cur] = SA;
		operations[cur + 1] = RA;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_pa_rb_pb(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == PA && operations[cur + 1] == RB
			&& operations[cur + 2] == PB))
	{
		*size -= 1;
		operations[cur] = SB;
		operations[cur + 1] = RB;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	change_operation(int *operations, int *size)
{
	int	i;

	i = 0;
	while (i < *size && operations)
	{
		check_pa_pb(operations, size, i);
		check_ra_rb(operations, size, i);
		check_pb_ra_pa(operations, size, i);
		check_pa_rb_pb(operations, size, i);
		i++;
	}
}

void	output_operation(int *operations, int size)
{
	int	i;

	i = 0;
	//change_operation(operations, &size);
	while (i < size)
	{
		print_operation(operations[i]);
		i++;
	}
}

int	*copy_operation(int size, int *keep, int new)
{
	int	i;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	i = 0;
	while (i < size - 1)
	{
		tmp[i] = keep[i];
		i++;
	}
	tmp[i] = new;
	if (size > 1)
		free(keep);
	return (tmp);
}

void	stack_operation(int operation)
{
	static int	size;
	static int	*keep;

	if (operation == END)
	{
		output_operation(keep, size);
		return ;
	}
	size++;
	keep = copy_operation(size, keep, operation);
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
	stack_operation(operation);
}

//void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation)
//{
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
//	print_stack(*stack_a, *stack_b);
//	print_operation(operation);
//	usleep(300000);
//}
