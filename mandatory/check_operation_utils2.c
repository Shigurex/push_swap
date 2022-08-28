/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:38:08 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 21:51:24 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	check_pa_rrb_pb(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == PA
			&& operations[cur + 1] == RRB && operations[cur + 2] == PB))
	{
		*size -= 1;
		operations[cur] = RRB;
		operations[cur + 1] = SB;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_sb_rb_pa(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == SB && operations[cur + 1] == RB
			&& operations[cur + 2] == PA))
	{
		*size -= 1;
		operations[cur] = PA;
		operations[cur + 1] = RB;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_sa_ra_pb(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == SA && operations[cur + 1] == RA
			&& operations[cur + 2] == PB))
	{
		*size -= 1;
		operations[cur] = PB;
		operations[cur + 1] = RA;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_sa_pb_ra(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == SA && operations[cur + 1] == PB
			&& operations[cur + 2] == RA))
	{
		*size -= 1;
		operations[cur] = RA;
		operations[cur + 1] = PB;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}

void	check_sb_pa_rb(int *operations, int *size, int cur)
{
	if (cur < *size - 2 && (operations[cur] == SB && operations[cur + 1] == PA
			&& operations[cur + 2] == RB))
	{
		*size -= 1;
		operations[cur] = RB;
		operations[cur + 1] = PA;
		cur += 2;
		while (cur < *size)
		{
			operations[cur] = operations[cur + 1];
			cur++;
		}
	}
}
