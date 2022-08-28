/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:35:32 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 17:29:17 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include	"stdlib.h"
# include	"libft/libft.h"

# define ERR 0
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

typedef struct s_stack {
	int	*array;
	int	size;
}	t_stack;

# define TRUE 1
# define FALSE 0

int		*input_argument(int argc, char **argv, int *size);
void	exit_error(int status);
void	do_swap(t_stack *stack);
void	do_push(t_stack *stack_from, t_stack *stack_to);
void	do_reverse(t_stack *stack);
void	do_reverse_rotate(t_stack *stack);
void	do_operation(t_stack *stack_a, t_stack *stack_b, int operation);
int		read_operation(char *str);
int		check_sorted(t_stack stack_a, t_stack stack_b);

#endif
