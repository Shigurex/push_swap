/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sixover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:45:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/13 18:15:39 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pb_all(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	mid;
	int	max;
	int	count;
	int	range;

	mid = stack_a->size / 3;
	max = mid;
	min = mid;
	while (stack_a->size > 10)
	{
		range = stack_a->size / 5;
		max += range * 2;
		min -= range;
		count = 0;
		while (count < range * 3)
		{
			if (min <= stack_a->array[0] && stack_a->array[0] < max)
			{
				do_operation(stack_a, stack_b, PB);
				if (stack_b->array[0] < mid)
					do_operation(stack_a, stack_b, RB);
				count++;
			}
			else
				do_operation(stack_a, stack_b, RA);
		}
	}
}

void	pb_remain(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	mid;
	int	range;

	count = 0;
	mid = size / 3;
	range = stack_a->size - 3;
	while (count < range)
	{
		if (stack_a->array[0] == size - 1 || stack_a->array[0] == size - 2
			|| stack_a->array[0] == size - 3)
			do_operation(stack_a, stack_b, RA);
		else
		{
			do_operation(stack_a, stack_b, PB);
			if (stack_b->array[0] < mid)
				do_operation(stack_a, stack_b, RB);
			count++;
		}
	}
}

void	check_insert_place(int max, t_stack *stack_a, t_stack *stack_b)
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

void	insertion_sort(int min, int max, t_stack *stack_a, t_stack *stack_b)
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

void	insertion_quick(int min, int max, t_stack *stack_a, t_stack *stack_b)
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
	while (count_b > 0)
	{
		do_operation(stack_a, stack_b, RRB);
		count_b--;
	}
	while (stack_a->array[0] > stack_a->array[stack_a->size - 1])
		do_operation(stack_a, stack_b, RRA);
	insertion_sort(min, mid, stack_a, stack_b);
}

void	pa_range(int min, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	count_a;
	int	count_b;

	mid = (min + max) / 2;
	if (max - min <= 40)
	{
		if (max - min <= 15)
			insertion_sort(min, max, stack_a, stack_b);
		else
			insertion_quick(min, max, stack_a, stack_b);
		return ;
	}
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
	while (count_b > 0)
	{
		do_operation(stack_a, stack_b, RRB);
		count_b--;
	}
	while (count_a > 0)
	{
		do_operation(stack_a, stack_b, PB);
		count_a--;
	}
	pa_range(mid, max, stack_a, stack_b);
	pa_range(min, mid, stack_a, stack_b);
}

static int	count_roop_num(int size)
{
	int	current;
	int	range;
	int	count;

	current = size;
	count = 0;
	while (current > 10)
	{
		range = current / 5;
		current -= range * 3;
		count++;
	}
	return (count);
}

int	*get_separator(int size)
{
	int	mid;
	int	roop;
	int	*separator;
	int	i;

	roop = count_roop_num(size);
	mid = size / 3;
	separator = malloc(sizeof(int) * ((roop + 1) * 2 + 1));
	separator[0] = size - 3;
	separator[roop + 1] = mid;
	separator[(roop + 1) * 2] = 0;
	i = 0;
	while (i < roop)
	{
		i++;
		separator[roop + 1 - i] = separator[roop + 1 - i + 1] + size / 5 * 2;
		separator[roop + 1 + i] = separator[roop + 1 + i - 1] - size / 5;
		size -= size / 5 * 3;
	}
	return (separator);
}

void	handle_sixover(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	*separator;
	int	i;

	pb_all(stack_a, stack_b);
	pb_remain(size, stack_a, stack_b);
	handle_three(stack_a, stack_b);
	separator = get_separator(size);
	i = 0;
	while (separator[i])
	{
		pa_range(separator[i + 1], separator[i], stack_a, stack_b);
		i++;
	}
}
