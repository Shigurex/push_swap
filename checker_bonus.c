/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:35:27 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/14 17:28:46 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

void	exit_error(int status)
{
	write(2, "Error\n", 6);
	exit(status);
}

static int	*compression(int *base_array, int size)
{
	int	i;
	int	j;
	int	count;
	int	*compressed_array;

	i = 0;
	compressed_array = malloc(sizeof(int) * size);
	if (compressed_array == NULL)
		exit_error(1);
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (base_array[j] < base_array[i])
				count++;
			j++;
		}
		compressed_array[i] = count;
		i++;
	}
	return (compressed_array);
}

static void	stack_init(t_stack *stack_a, t_stack *stack_b, int size, int *array)
{
	stack_a->array = compression(array, size);
	stack_a->size = size;
	stack_b->array = malloc(sizeof(unsigned int) * size);
	stack_b->size = 0;
}

void	initialize(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	*base_array;

	size = 0;
	base_array = input_argument(argc, argv, &size);
	stack_init(stack_a, stack_b, size, base_array);
	free(base_array);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		operation;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (1);
	initialize(argc, argv, &stack_a, &stack_b);
	while (1)
	{
		str = get_next_line(0);
		operation = read_operation(str);
		if (operation == ERR)
			break ;
		do_operation(&stack_a, &stack_b, operation);
		free(str);
	}
	if (check_sorted(stack_a, stack_b) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
