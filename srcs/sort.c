/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/09 08:49:08 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_infos *infos)
{
	t_elem	*tmp;

	while (!check_sorted(infos))
	{
		tmp = infos->first_a;
		if (tmp->nb > tmp->next->nb)
		{
			if (tmp->next->next && tmp->nb > tmp->next->next->nb)
			{
				write(1, "ra\n", 3);
				rotate_a(infos);
			}
			else
			{
				write(1, "sa\n", 3);
				swap_a(infos);
			}
			
		}
		else if(infos->size > 2)
		{
			tmp = tmp->next;
			if (tmp->nb > tmp->next->nb)
			{
				write(1, "rra\n", 4);
				reverse_ra(infos);
			}
		}
	}
}

void	begin_sort(t_infos *infos)
{
	if (infos->size <= 3)
		sort_three(infos);
}
