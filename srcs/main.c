/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:56:49 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 13:26:34 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		input_error(int ac, char **av)
{
	int	i;

	(void)av;
	i = 1;
	if (ac == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (input_error(ac, av))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	create_stack(ac, av);
	return (0);
}
