/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_and_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:14:00 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 19:16:16 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	check_insert_place(int max, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->array[0] < stack_a->array[0])
	{
		if (stack_a->array[stack_a->size - 1] >= max
			|| stack_b->array[0] > stack_a->array[stack_a->size - 1])
			do_operation(stack_a, stack_b, PA);
		else
		{
			while (stack_b->array[0] < stack_a->array[stack_a->size - 1]
				&& stack_a->array[stack_a->size - 1] < max)
				do_operation(stack_a, stack_b, RRA);
			do_operation(stack_a, stack_b, PA);
		}
	}
	else
	{
		while (stack_b->array[0] > stack_a->array[0])
			do_operation(stack_a, stack_b, RA);
		do_operation(stack_a, stack_b, PA);
	}
}

static void	insertion_sort(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (count < max - min)
	{
		check_insert_place(max, stack_a, stack_b);
		count++;
	}
	while (stack_a->array[0] > stack_a->array[stack_a->size - 1])
		do_operation(stack_a, stack_b, RRA);
}

static void	quick_insert(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	count_a;
	int	count_b;

	mid = (min + max) / 2;
	count_a = 0;
	count_b = 0;
	while (count_a < max - mid)
	{
		if (mid <= stack_b->array[0] && stack_b->array[0] < max)
		{
			check_insert_place(max, stack_a, stack_b);
			count_a++;
		}
		else
		{
			do_operation(stack_a, stack_b, RB);
			count_b++;
		}
	}
	repeat(stack_a, stack_b, RRB, count_b);
	while (stack_a->array[0] > stack_a->array[stack_a->size - 1])
		do_operation(stack_a, stack_b, RRA);
	insertion_sort(min, mid, stack_a, stack_b);
}

static void	quicksort(int mid, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	count_b = 0;
	while (count_a < max - mid)
	{
		if (mid <= stack_b->array[0] && stack_b->array[0] < max)
		{
			do_operation(stack_a, stack_b, PA);
			count_a++;
		}
		else
		{
			do_operation(stack_a, stack_b, RB);
			count_b++;
		}
	}
	repeat(stack_a, stack_b, RRB, count_b);
	repeat(stack_a, stack_b, PB, count_a);
}

void	pa_range(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	mid;

	mid = (min + max) / 2;
	if (max - min <= 40)
	{
		if (max - min <= 15)
			insertion_sort(min, max, stack_a, stack_b);
		else
			quick_insert(min, max, stack_a, stack_b);
		return ;
	}
	quicksort(mid, max, stack_a, stack_b);
	pa_range(mid, max, stack_a, stack_b);
	pa_range(min, mid, stack_a, stack_b);
}
