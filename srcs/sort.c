/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/11 11:27:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_infos *infos)
{
	t_elem	*tmp;

	while (!check_sorted_list(infos->first_a))
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

void	sort_five(t_elem *first)
{
	t_elem	*tmp;

	tmp = first;
}

void	sort_list(t_infos *infos)
{
	size_t	count;

	count = 0;
	while (count < infos->size_a)
	{
		if (infos->first_a->nb >= infos->median)
			push_b(infos);
		else
			rotate_a(infos);
		count++;
	}
	print_list(infos->first_a);
	print_list(infos->first_b);
}

void	begin_sort(t_infos *infos)
{
	fill_array(infos);
	infos->array = sort_array(infos->array, infos->size);
	infos->median = infos->array[infos->size / 2];
	if (infos->size <= 3)
		sort_three(infos);
	else
		sort_list(infos);
}
