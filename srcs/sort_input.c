/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:35:39 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/16 11:00:05 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_array(t_infos *infos)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = infos->first_a;
	while (tmp)
	{
		infos->array[i] = tmp->nb;
		i++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

int		*sort_array(int *array, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;
	int				tmp2;

	i = 0;
	while (++i < size)
	{
		j = i - 1;
		while (array[i++] > array[j])
			j++;
		if (i < size && array[j] > array[i])
		{
			while (j > 0 && array[i] < array[j - 1])
				j--;
			tmp = i;
			tmp2 = array[i];
			while (--i > j)
				array[i + 1] = array[i];
			array[j] = tmp2;
			i = tmp;
		}
	}
	return (array);
}
