/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:17:06 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/13 20:50:21 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

void	do_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
}

void	do_push(t_stack *stack_from, t_stack *stack_to)
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
}

void	do_reverse(t_stack *stack)
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
}

void	do_reverse_rotate(t_stack *stack)
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
}
