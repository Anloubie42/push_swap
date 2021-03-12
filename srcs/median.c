/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:23:32 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/12 14:24:53 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_median(int *array, unsigned int size)
{
	return (array[size / 2]);
}

int		get_median_list(t_elem *first, unsigned int size)
{
	int		*array;
	t_elem	*tmp;
	int		i;
	int		median;

	i = 0;
	array = (int*)malloc(sizeof(int) * size);
	if (!array)
		return (0);
	tmp = first;
	while (tmp)
	{
		array[i] = tmp->nb;
		i++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	array = sort_array(array, size);
	median = get_median(array, size);
	free(array);
	return (median);
}