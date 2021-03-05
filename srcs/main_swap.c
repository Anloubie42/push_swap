/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:12 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 15:49:34 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_infos	*infos;

	infos = (t_infos*)malloc(sizeof(t_infos));
	if (!infos)
		return (0);
	if (input_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	create_stack(ac, av, infos);
	begin_sort(infos);
	return (0);
}
