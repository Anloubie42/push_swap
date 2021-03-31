/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:57:28 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/31 09:01:23 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	long	mult;

	i = 0;
	res = 0;
	mult = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * mult);
}
