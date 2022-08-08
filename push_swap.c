/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:53:52 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/08 22:00:03 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	exit_safe(int *base_array)
{
	free(base_array);
	exit(1);
}

int	atoi_within_int(const char *str, int *base_array)
{
	size_t	i;
	int		sign;
	long	value;

	i = 0;
	value = 0;
	sign = 1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			value = 10 * value + (str[i] - '0');
			if ((sign == 1 && value > (long)INT_MAX)
				|| (sign == -1 && value > -(long)INT_MIN))
				exit_safe(base_array);
			i++;
		}
		else
			exit_safe(base_array);
	}
	return ((int)(sign * value));
}

int	*input_data(int size, char **str)
{
	int	*base_array;
	int	i;
	int	j;

	base_array = malloc(sizeof(int) * size);
	if (base_array == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		base_array[i] = atoi_within_int(str[i], base_array);
		j = 0;
		while (j < i)
		{
			if (base_array[i] == base_array[j])
				exit_safe(base_array);
			j++;
		}
		i++;
	}
	return (base_array);
}

int	*compression(int *base_array, int size)
{
	int	i;
	int	j;
	int	count;
	int	*compressed_array;

	i = 0;
	compressed_array = malloc(sizeof(int) * size);
	if (compressed_array == NULL)
		exit_safe(base_array);
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

void	stack_init(t_stack *stack_a, t_stack *stack_b, int size, int *base_array)
{
	stack_a->array = compression(base_array, size);
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

	size = argc - 1;
	if (size == 0)
		return (1);
	base_array = input_data(size, &argv[1]);
	stack_init(&stack_a, &stack_b, size, base_array);
	free(base_array);
	pb_half(0, size, &stack_a, &stack_b);
	//print_stack(stack_a, stack_b);
	do_operation(&stack_a, &stack_b, END);
	return (0);
}
