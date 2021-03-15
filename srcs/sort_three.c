/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:50:32 by antoine           #+#    #+#             */
/*   Updated: 2021/03/15 17:50:58 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_reverse(t_infos *infos)
{
	t_elem	*tmp;

	if (!infos->first_a)
		return ;
	while (!check_sorted_list_reverse(infos->first_a))
	{
		tmp = infos->first_a;
		if (tmp->nb < tmp->next->nb)
		{
			if (tmp->next->next && tmp->nb < tmp->next->next->nb)
				print_ra(infos);
			else
				print_sa(infos);
		}
		else if(infos->size_a > 2)
		{
			tmp = tmp->next;
			if (tmp->nb < tmp->next->nb)
				print_rra(infos);
		}
	}
}

void	sort_three_a(t_infos *infos)
{
	t_elem	*tmp;

	while (infos->a && !check_sorted_list(infos->first_a))
	{
		tmp = infos->first_a;
		if (tmp->nb > tmp->next->nb)
		{
			if (tmp->next->next && tmp->nb > tmp->next->next->nb)
				print_ra(infos);
			else
				print_sa(infos);
		}
		else if(infos->size_a > 2)
		{
			tmp = tmp->next;
			if (tmp->nb > tmp->next->nb)
				print_rra(infos);
		}
	}
}
