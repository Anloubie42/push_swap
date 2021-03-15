/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/15 17:50:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_infos *infos)
{
	size_t	count;
	size_t	size;
	int		i;
	int		median;
	t_bloc	*b;

	b = NULL;
	while (!(check_sorted_list_reverse(infos->b) && !infos->a))
	{
		while (infos->size_a > 3)
		{
			count = 0;
			size = infos->size_a;
			median = get_median_list(infos->first_a, infos->size_a);
			add_bloc_front(&b, new_bloc());
			while (count < size)
			{
				if (infos->first_a->nb < median)
				{
					print_pb(infos);
					b->size++;
				}
				else
					print_ra(infos);
				count++;
			}
		}
		sort_three_a_reverse(infos);
		while (infos->size_a > 0)
		{
			print_pb(infos);
			print_rb(infos);
		}
		i = -1;
		while (b && ++i < (int)b->size)
			print_pa(infos);
		free_front_bloc(&b);
	}
	while (infos->first_b)
		print_pa(infos);
	print_list(infos->a);
	print_list(infos->b);
}

void	begin_sort(t_infos *infos)
{
	fill_array(infos);
	infos->array = sort_array(infos->array, infos->size);
	infos->median = infos->array[infos->size / 2];
	if (infos->size <= 3)
		sort_three_a(infos);
	else
		sort_list(infos);
}
