/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:57:02 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 00:42:05 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"stdio.h"
# include	"stdlib.h"
# include	"limits.h"
# include	"libft/libft.h"

# define NONE 0
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define END 12

typedef struct s_stack {
	int	*array;
	int	size;
}	t_stack;

int		*input_argument(int argc, char **argv, int *size);
void	do_swap(t_stack *stack);
void	do_push(t_stack *stack_from, t_stack *stack_to);
void	do_reverse(t_stack *stack);
void	do_reverse_rotate(t_stack *stack);
void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation);
void	print_stack(t_stack stack_a, t_stack stack_b); //need deleted
void	handle_two(t_stack *stack_a, t_stack *stack_b);
void	quicksort(int size, t_stack *stack_a, t_stack *stack_b);

#endif
