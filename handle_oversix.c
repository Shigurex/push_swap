/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oversix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/09 19:11:37 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pa_half(int min, int max, t_stack *stack_a, t_stack *stack_b);

//void	ra_three(t_stack *stack_a, t_stack *stack_b)
//{
//	int	top;
//	int	middle;
//	int	bottom;

//	top = stack_a->array[0];
//	middle = stack_a->array[1];
//	bottom = stack_a->array[2];
//	if (top < middle && middle < bottom)
//	{
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//	}
//	else if (top < bottom && bottom < middle)
//	{
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//	}
//	else if (middle < top && top < bottom)
//	{
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//	}
//	else if (bottom < top && top < middle)
//	{
//		do_operation(stack_a, stack_b, PB);
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, PA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//	}
//	else if (middle < bottom && bottom < top)
//	{
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//	}
//	else
//	{
//		do_operation(stack_a, stack_b, PB);
//		do_operation(stack_a, stack_b, SA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, RA);
//		do_operation(stack_a, stack_b, PA);
//		do_operation(stack_a, stack_b, RA);
//	}
//}

void	pb_all(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	if (max - min <= 2)
	{
		if (max - min == 1)
			do_operation(stack_a, stack_b, RA);
		if (max - min == 2)
		{
			handle_two(stack_a, stack_b);
			do_operation(stack_a, stack_b, RA);
			do_operation(stack_a, stack_b, RA);
		}
		return ;
	}
	count = 0;
	while (1)
	{
		if (count == max - min)
			break ;
		if (stack_a->array[0] == min)
		{
			do_operation(stack_a, stack_b, RA);
			min++;
		}
		else
		{
			do_operation(stack_a, stack_b, PB);
			count++;
		}
	}
	pa_half(min, max, stack_a, stack_b);
}

void	pa_half(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	mid;

	mid = (min + max) / 2;
	count = 0;
	if (max - min < 1)
		return ;
	while (1)
	{
		if (count == max - mid)
			break ;
		if (mid <= stack_b->array[0] && stack_b->array[0] < max)
		{
			do_operation(stack_a, stack_b, PA);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RB);
	}
	while (1)
	{
		if (count == max - min)
			break ;
		if (stack_b->array[0] == min)
		{
			do_operation(stack_a, stack_b, PA);
			do_operation(stack_a, stack_b, RA);
			min++;
		}
		else
		{
			do_operation(stack_a, stack_b, PA);
			count++;
		}
	}
	pb_all(min, mid, stack_a, stack_b);
	pb_all(mid, max, stack_a, stack_b);
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
	while (1)
	{
		if (count == mid - min)
			break ;
		if (min <= stack_a->array[0] && stack_a->array[0] < mid)
		{
			do_operation(stack_a, stack_b, PB);
			count++;
		}
		else
			do_operation(stack_a, stack_b, RA);
	}
	pa_half(min, mid, stack_a, stack_b);
	pb_all(mid, max, stack_a, stack_b);
}
