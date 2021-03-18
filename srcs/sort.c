/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/18 15:26:48 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	breakpoint(t_infos *infos)
{
	printf("a = ");
	print_list(infos->a);
	printf("b = ");
	print_list(infos->b);
	read(0, NULL, 1);
}

void	sort_list(t_infos *infos)
{
	size_t			count;
	size_t			size;
	size_t			a;
	int				median;
	t_bloc			*b;
	t_bloc			*bloc_a;

	b = NULL;
	bloc_a = NULL;
	a = 3;
	while (!check_sorted(infos))
	{
		while (infos->size_a > a)
		{
			count = 0;
			size = infos->size_a;
			median = get_median_list(infos->first_a, infos->size_a);
			add_bloc_front(&b, new_bloc());
			while (infos->size_a > a && count < size)
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
		sort_three(infos);
		add_bloc_front(&bloc_a, new_bloc());
		bloc_a->size = infos->size_a - get_size(bloc_a);
		count = -1;
		a = infos->size_a + 3;
		while (b && ++count < b->size)
			print_pa(infos);
		free_front_bloc(&b);
	}
}

// void	sort_list(t_infos *infos)
// {
// 	size_t	count;
// 	size_t	size;
// 	int		median;
// 	t_bloc	*b;

// 	b = NULL;
// 	while (!(check_sorted_list_reverse(infos->b) && !infos->a))
// 	{
// 		while (infos->size_a > 3)
// 		{
// 			count = 0;
// 			size = infos->size_a;
// 			median = get_median_list(infos->first_a, infos->size_a);
// 			add_bloc_front(&b, new_bloc());
// 			while (count < size)
// 			{
// 				if (infos->first_a->nb < median)
// 				{
// 					print_pb(infos);
// 					b->size++;
// 				}
// 				else
// 					print_ra(infos);
// 				count++;
// 			}
// 		}
// 		sort_three_a_reverse(infos);
// 		while (infos->size_a > 0)
// 		{
// 			print_pb(infos);
// 			print_rb(infos);
// 		}
// 		count = -1;
// 		while (b && ++count < b->size)
// 			print_pa(infos);
// 		free_front_bloc(&b);
// 	}
// 	while (infos->first_b)
// 		print_pa(infos);
// }

void	begin_sort(t_infos *infos)
{
	// fill_array(infos);
	// infos->array = sort_array(infos->array, infos->size);
	// infos->median = infos->array[infos->size / 2];
	// sort_three(infos);
	if (infos->size <= 3)
		sort_three_a(infos);
	else if (infos->size <= 5)
		sort_five(infos);
	else
		sort_list(infos);
}
