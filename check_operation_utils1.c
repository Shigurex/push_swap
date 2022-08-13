/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:37:56 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 22:14:44 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	check_pa_pb(int *operations, int *size, int cur)
{
	int	i;

	i = 0;
	while (0 <= cur - i && cur + 1 + i < *size
		&& ((operations[cur - i] == PA && operations[cur + 1 + i] == PB)
			|| (operations[cur - i] == PB && operations[cur + 1 + i] == PA)))
		i++;
	if (i > 0)
	{
		*size -= 2 * i;
		while (cur < *size + i - 1)
		{
			operations[cur - i + 1] = operations[cur + 1 + i];
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

void	check_pb_rra_pa(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == PB && operations[cur + 1] == RRA
			&& operations[cur + 2] == PA))
	{
		*size -= 1;
		operations[cur] = RRA;
		operations[cur + 1] = SA;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}
