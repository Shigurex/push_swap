/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oversix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/08 21:45:47 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pa_half(int min, int max, t_stack *stack_a, t_stack *stack_b);

void	pb_two_half(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	i;

	mid = (min + max) / 2;
	if (max - min <= 2)
	{
		handle_two(stack_a, stack_b);
		return ;
	}
	i = 0;
	while (i < mid - min)
	{
		do_operation(stack_a, stack_b, RRA);
		i++;
	}
	i = 0;
	while (i < max - min)
	{
		do_operation(stack_a, stack_b, PB);
		i++;
	}
	pa_half(mid, max, stack_a, stack_b);
	pa_half(min, mid, stack_a, stack_b);
}

void	pa_half(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	mid;
	int	flag;

	mid = (min + max) / 2;
	count = 0;
	flag = 1;
	if (max - min <= 2)
		flag = 0;
	while (1)
	{
		if (min <= stack_b->array[0] && stack_b->array[0] < max)
		{
			do_operation(stack_a, stack_b, PA);
			if (min <= stack_a->array[0] && stack_a->array[0] < mid && flag == 1)
				do_operation(stack_a, stack_b, RA);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RB);
		if (count == max - min)
			break ;
	}
	pb_two_half(min, max, stack_a, stack_b);
}

void	pb_half(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	mid;

	mid = (min + max) / 2;
	count = 0;
	if (max - min <= 2)
	{
		handle_two(stack_a, stack_b);
		return ;
	}
	printf("min:%d, max:%d, mid:%d\n", min, max, mid);
	while (1)
	{
		if (min <= stack_a->array[0] && stack_a->array[0] < mid)
		{
			do_operation(stack_a, stack_b, PB);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RA);
		if (count == mid - min)
			break ;
	}
	pb_half(mid, max, stack_a, stack_b);
	pa_half(min, mid, stack_a, stack_b);
}

// min <= x < max

//void	main(void)
//{
//	int	size;

//	size = 100;
//	recursion(0, size / 3)
//	recursion(size / 3, size / 3 * 2)
//	recursion(size / 3 * 2, size)
//}
