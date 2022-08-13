/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:59:42 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/13 18:00:02 by yahokari         ###   ########.fr       */
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

static void	change_operation(int *operations, int *size)
{
	int	i;

	i = 0;
	while (i < *size && operations)
	{
		check_pa_pb(operations, size, i);
		check_ra_rb(operations, size, i);
		check_pb_ra_pa(operations, size, i);
		check_pa_rb_pb(operations, size, i);
		check_pb_rra_pa(operations, size, i);
		check_pa_rrb_pb(operations, size, i);
		check_sb_rb_pa(operations, size, i);
		check_sa_ra_pb(operations, size, i);
		check_sa_pb_ra(operations, size, i);
		check_sb_pa_rb(operations, size, i);
		i++;
	}
}

static void	output_operation(int *operations, int size)
{
	int	i;

	i = 0;
	change_operation(operations, &size);
	while (i < size)
	{
		print_operation(operations[i]);
		i++;
	}
}

static int	*copy_operation(int size, int *keep, int new)
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
		free(keep);
		return ;
	}
	size++;
	keep = copy_operation(size, keep, operation);
}
