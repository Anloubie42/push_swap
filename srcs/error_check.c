/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:19:52 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/31 09:05:26 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_off_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (1);
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f'
		&& c != ' ')
		return (0);
	return (1);
}

int	is_all_digits(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	middle_dash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i != 0 && !ft_isspace(str[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

int	input_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		return (1);
	while (i < ac)
	{
		if (is_off_int(av[i]))
			return (1);
		if (is_all_digits(av[i]) == 0)
			return (1);
		if (middle_dash(av[i]))
			return (1);
		j = 1;
		while (j < i)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
