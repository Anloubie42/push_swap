/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:35:39 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/18 10:12:29 by anloubie         ###   ########.fr       */
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
		j = i - 2;
		while (array[i] > array[++j])
			i++;
		if (i < size && array[j] > array[i])
		{
			while (j > 0 && array[i] < array[j - 1])
				j--;
			tmp = i;
			tmp2 = array[i++];
			while (--i > j)
				array[i] = array[i - 1];
			array[j] = tmp2;
			i = tmp;
		}
	}
	return (array);
}
