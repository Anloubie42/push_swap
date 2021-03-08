/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/08 01:18:03 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_infos *infos)
{
	push_b(infos);
	if (infos->size > 4)
		push_b(infos);
	printf("hello\n");
	sort_three(infos);
	// print_list(infos->first_a);
	// print_list(infos->first_b);
	if (infos->first_b->nb < infos->first_b->next->nb)
		swap_b(infos);
	push_a(infos);
	if (infos->first_a->nb > infos->first_a->next->nb)
	{
		if (infos->first_a->nb < find_last_elem(infos->first_a)->nb)
		{
			write(1, "sa\n", 3);
			swap_a(infos);
		}
		else
		{
			write(1, "rra\nsa\nra\nra\n", 13);
			reverse_ra(infos);
			swap_a(infos);
			rotate_a(infos);
			rotate_a(infos);
		}
	}
}

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
	else if (infos->size <= 5)
		sort_five(infos);
}
