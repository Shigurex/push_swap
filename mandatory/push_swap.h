/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:57:02 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 19:14:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"stdlib.h"
# include	"../libft/libft.h"

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
void	handle_three(t_stack *stack_a, t_stack *stack_b);
void	handle_fiveunder(int size, t_stack *stack_a, t_stack *stack_b);
void	handle_sixover(int size, t_stack *stack_a, t_stack *stack_b);
void	stack_operation(int operation);
void	check_pa_pb(int *operations, int *size, int cur);
void	check_ra_rb(int *operations, int *size, int cur);
void	check_pb_ra_pa(int *operations, int *size, int cur);
void	check_pa_rb_pb(int *operations, int *size, int cur);
void	check_pb_rra_pa(int *operations, int *size, int cur);
void	check_pa_rrb_pb(int *operations, int *size, int cur);
void	check_sb_rb_pa(int *operations, int *size, int cur);
void	check_sa_ra_pb(int *operations, int *size, int cur);
void	check_sa_pb_ra(int *operations, int *size, int cur);
void	check_sb_pa_rb(int *operations, int *size, int cur);
void	repeat(t_stack *stack_a, t_stack *stack_b, int operation, int rep);
int		count_roop_num(int size);
int		*get_separator(int size);
void	pa_range(int min, int max, t_stack *stack_a, t_stack *stack_b);


#endif
