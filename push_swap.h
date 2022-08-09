/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:57:02 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/09 18:03:24 by yahokari         ###   ########.fr       */
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

typedef struct s_stack {
	int	*array;
	int	size;
}	t_stack;

int		*input_argument(int argc, char **argv, int *size);
void	do_swap(t_stack *stack, int *flag);
void	do_push(t_stack *stack_from, t_stack *stack_to, int *flag);
void	do_reverse(t_stack *stack, int *flag);
void	do_reverse_rotate(t_stack *stack, int *flag);
void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation);
void	print_stack(t_stack stack_a, t_stack stack_b); //need deleted
void	handle_two(t_stack *stack_a, t_stack *stack_b);
void	pb_half(int min, int max, t_stack *stack_a, t_stack *stack_b);

#endif
