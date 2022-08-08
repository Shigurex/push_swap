/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:57:02 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/08 20:24:51 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"stdio.h"
# include	"stdlib.h"
# include	"limits.h"
# include	"libft/libft.h"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define END 11

typedef struct s_stack {
	int	*array;
	int	size;
}	t_stack;

void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation);
void	pb_half(int min, int max, t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack stack_a, t_stack stack_b);
void	handle_two(t_stack *stack_a, t_stack *stack_b);

#endif
