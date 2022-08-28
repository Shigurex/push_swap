/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:26:26 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 17:26:41 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

int	check_sorted(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.size > 0)
		return (FALSE);
	i = 0;
	while (i < stack_a.size - 1)
	{
		if (stack_a.array[i] > stack_a.array[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
