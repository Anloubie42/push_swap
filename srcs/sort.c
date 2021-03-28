/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:38 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/28 18:58:16 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_infos *infos)
{
	t_bloc			*b;
	t_bloc			*bloc_a;

	b = NULL;
	bloc_a = NULL;
	while (!check_sorted(infos))
	{
		split_stack_a(infos, &bloc_a, &b);
		sort_three(infos);
		if (b)
			split_stack_b(infos, &bloc_a, &b);
	}
	free_blocs(bloc_a);
	free_blocs(b);
}

void	begin_sort(t_infos *infos)
{
	if (infos->size <= 3)
		sort_three_a(infos);
	else if (infos->size <= 5)
		sort_five(infos);
	else
		sort_list(infos);
}
