/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/12 15:51:08 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b(t_infos *infos)
{
	t_elem	*tmp;

	while (!check_sorted_list_reverse(infos->first_b))
	{
		tmp = infos->first_b;
		if (tmp->nb < tmp->next->nb)
		{
			if (tmp->next->next && tmp->nb < tmp->next->next->nb)
			{
				write(1, "rb\n", 3);
				rotate_b(infos);
			}
			else
			{
				write(1, "sb\n", 3);
				swap_b(infos);
			}
			
		}
		else if(infos->size_b > 2)
		{
			tmp = tmp->next;
			if (tmp->nb < tmp->next->nb)
			{
				write(1, "rrb\n", 4);
				reverse_rb(infos);
			}
		}
	}
}

void	sort_three_a(t_infos *infos)
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
		else if(infos->size_a > 2)
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

void	sort_list(t_infos *infos)
{
	size_t	count;
	size_t	size;
	int		i;
	int		median;
	t_bloc	*b;

	b = new_bloc();
	while (!check_sorted(infos))
	{
		while (infos->size_a > 3)
		{
			i = -1;
			count = 0;
			size = infos->size_a;
			median = get_median_list(infos->first_a, infos->size_a);
			add_bloc_front(&b, new_bloc());
			while (count < size)
			{
				if (infos->first_a->nb >= median)
				{
					push_b(infos);
					b->size++;
				}
				else
					rotate_a(infos);
				count++;
			}
		}
		sort_three_a(infos);
		while (++i < (int)infos->size_a)
		{
			push_b(infos);
			rotate_b(infos);
		}
		i = -1;
		while (b && ++i < (int)b->size)
			push_a(infos);
		free_front_bloc(&b);
		print_list(infos->a);
		print_list(infos->b);
		if (!infos->a)
		{
			while (infos->first_b)
				push_a(infos);
			i = 0;
			while (i < (int)infos->size_a)
			{
				rotate_a(infos);
				i++;
			}
		}
	}
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
