/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 08:54:25 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/27 12:30:12 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack_a(t_infos *infos, t_bloc **bloc_a, t_bloc **b)
{
	size_t	count;
	size_t	size;
	int		median;

	while ((*bloc_a && (*bloc_a)->size > 3) || (!*bloc_a && infos->size_a > 3))
	{
		count = 0;
		size = ((*bloc_a)) ? (*bloc_a)->size : infos->size_a;
		median = get_median_list(infos->first_a, size);
		add_bloc_front(b, new_bloc());
		while (((*b)->size < (size / 2)))
		{
			if (infos->first_a->nb < median)
			{
				print_pb(infos);
				(*b)->size++;
				((*bloc_a)) ? (*bloc_a)->size-- : 0;
			}
			else if ((*b)->size < (size / 2))
				print_ra(infos);
			count++;
		}
		while ((*bloc_a) && (*b) && count-- > (*b)->size)
			print_rra(infos);
	}
}

void	split_stack_b(t_infos *infos, t_bloc **bloc_a, t_bloc **b)
{
	size_t	count;
	size_t	size;
	int		median;

	add_bloc_front(bloc_a, new_bloc());
	size = (*b)->size;
	median = get_median_list(infos->b, (*b)->size);
	count = 0;
	while ((size <= 3 && count < size) || (size > 3 && (*b)->size > (size / 2)))
	{
		if (size <= 3 || infos->first_b->nb >= median)
		{
			print_pa(infos);
			(*bloc_a)->size++;
			(*b)->size--;
		}
		else
			print_rb(infos);
		count++;
	}
	while ((*b)->next && size > 3 && count-- > (*bloc_a)->size)
		print_rrb(infos);
	if ((*b)->size <= 0)
		free_front_bloc(b);
}
