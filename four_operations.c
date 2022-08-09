/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:17:06 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/09 18:02:08 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	do_swap(t_stack *stack, int *flag)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	*flag = 1;
}

void	do_push(t_stack *stack_from, t_stack *stack_to, int *flag)
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
	*flag = 1;
}

void	do_reverse(t_stack *stack, int *flag)
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
	*flag = 1;
}

void	do_reverse_rotate(t_stack *stack, int *flag)
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
	*flag = 1;
}
