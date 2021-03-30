/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 08:15:47 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/30 00:00:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_infos *infos)
{
	unsigned int	count;
	unsigned int	size;
	int				median;

	count = 0;
	size = 2;
	if (infos->size == 5)
		size = 3;
	while (!check_sorted(infos))
	{
		median = get_median_list(infos->a, infos->size_a);
		while (infos->size_a > size)
		{
			if (infos->first_a->nb < median)
				print_pb(infos);
			else
				print_ra(infos);
		}
		sort_three_a(infos);
		if (infos->b->nb < infos->b->next->nb)
			print_sb(infos);
		while (++count < 3)
			print_pa(infos);
	}
}
