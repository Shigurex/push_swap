/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:40:45 by yahokari          #+#    #+#             */
/*   Updated: 2022/08/09 18:00:02 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	atoi_within_int(const char *str)
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
				exit(1);
			i++;
		}
		else
			exit(1);
	}
	return ((int)(sign * value));
}

static int	*input_data(int size, char **str)
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
		base_array[i] = atoi_within_int(str[i]);
		j = 0;
		while (j < i)
		{
			if (base_array[i] == base_array[j])
				exit(1);
			j++;
		}
		i++;
	}
	return (base_array);
}

static int	count_arg(char **str)
{
	int	size;

	size = 0;
	while (str[size] != NULL)
		size++;
	return (size);
}

static void	free_arg_data(char **arg_data)
{
	size_t	i;

	i = 0;
	while (arg_data[i])
	{
		free(arg_data[i]);
		i++;
	}
	free(arg_data);
}

int	*input_argument(int argc, char **argv, int *size)
{
	char	**arg_data;
	int		*base_array;

	if (argc == 2)
	{
		arg_data = ft_split(argv[1], ' ');
		*size = count_arg(arg_data);
		base_array = input_data(*size, arg_data);
		free_arg_data(arg_data);
	}
	else
	{
		*size = argc - 1;
		base_array = input_data(*size, &argv[1]);
	}
	return (base_array);
}
