/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:56:49 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/31 09:30:36 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_infos	*infos;

	if (input_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	infos = (t_infos*)malloc(sizeof(t_infos));
	if (!infos)
		return (0);
	create_stack(ac, av, infos);
	wait_instructions(infos);
	free_exit(infos, 0);
	return (0);
}
