/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:53:52 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/11 16:59:15 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	*compression(int *base_array, int size)
{
	int	i;
	int	j;
	int	count;
	int	*compressed_array;

	i = 0;
	compressed_array = malloc(sizeof(int) * size);
	if (compressed_array == NULL)
		exit(1);
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

void	stack_init(t_stack *stack_a, t_stack *stack_b, int size, int *array)
{
	stack_a->array = compression(array, size);
	stack_a->size = size;
	stack_b->array = malloc(sizeof(unsigned int) * size);
	stack_b->size = 0;
}

void	print_stack(t_stack stack_a, t_stack stack_b)
{
	int	i;

	i = 0;
	printf("--------------------stack_a--------------------\n");
	while (i < stack_a.size)
	{
		printf("%d\n", stack_a.array[i]);
		i++;
	}
	printf("--------------------stack_b--------------------\n");
	i = 0;
	while (i < stack_b.size)
	{
		printf("%d\n", stack_b.array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*base_array;
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (1);
	size = 0;
	base_array = input_argument(argc, argv, &size);
	stack_init(&stack_a, &stack_b, size, base_array);
	free(base_array);
	//print_stack(stack_a, stack_b);
	quicksort(size, &stack_a, &stack_b);
	do_operation(&stack_a, &stack_b, END);
	//print_stack(stack_a, stack_b);
	exit (0);
}
