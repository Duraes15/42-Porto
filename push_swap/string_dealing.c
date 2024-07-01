/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dealing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:13 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/28 18:42:33 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	there_is_dup_numbers(char **sections)
{
	int		*numbers;
	int		j;
	int		len;

	len = 0;
	while (sections[len])
		len++;
	numbers = malloc(sizeof(int) * len);
	len = -1;
	while (sections[++len])
		numbers[len] = (int)ft_atoi_check_l(sections[len]);
	while (--len > 0)
	{
		j = len - 1;
		while (j >= 0)
		{
			if (numbers[len] == numbers[j--])
			{
				free(numbers);
				return (1);
			}
		}
	}
	free(numbers);
	return (0);
}

// it will free the strings produced by the 
// whole argv[1] when the argc is equal to 2
void	free_separations(char **separations)
{
	int	i;

	i = 0;
	while (separations[i] != NULL)
	{
		free(separations[i]);
		i++;
	}
	free(separations);
}

// it will convert the string to long
// if the string is not a number or as another type of elements,...
// ... this function is going to return a number bigger than the..
// ... MAX_INT,  because, on just_numbers function, it'll...
// ... lead to an error
long	ft_atoi_check_l(const char *nptr)
{
	long	n;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			n = (n * 10) + (nptr[i] - 48);
		else
			return (2147483649);
		i++;
	}
	return ((long)n * negative);
}

// this function will check if the string is just numbers
int	just_numbers(char *str)
{
	long	atoi_result;

	atoi_result = ft_atoi_check_l(str);
	if (atoi_result > 2147483647 || atoi_result < -2147483648)
		return (0);
	return (1);
}

// here, im going to gather every argument into one and then...
// ...separate them by the ' ' character in orther...
// ...to just deal with one case, that is when the arguments...
// ...are like that: 42 teste one -1 ...
// ...(it will cause an error, in this case)
char	**join_args(char **argv)
{
	char	*tmp;
	char	*str;
	char	**separated;
	int		i;

	i = 1;
	tmp = ft_strdup(" ");
	while (argv[i])
	{
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = ft_strjoin(str, " \0");
		free(str);
		i++;
	}
	separated = ft_split(tmp, ' ');
	free(tmp);
	return (separated);
}
