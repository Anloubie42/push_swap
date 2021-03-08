/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:12 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 20:15:25 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (check_sorted(infos))
		free_exit(infos);
	begin_sort(infos);
	return (0);
}
