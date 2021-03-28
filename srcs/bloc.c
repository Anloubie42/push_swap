/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:22:56 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/25 23:06:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bloc	*fill_bloc(t_infos *infos)
{
	t_bloc	*bloc;

	bloc = new_bloc();
	bloc->size = infos->size_a;
	return (bloc);
}

size_t	get_bloc_size(t_bloc *first)
{
	t_bloc	*tmp;
	size_t	sum;

	sum = 0;
	if (!first)
		return (sum);
	tmp = first;
	while (tmp)
	{
		sum += tmp->size;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (sum);
}
