/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:35:39 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/10 13:25:35 by antoine          ###   ########.fr       */
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

	i = 1;
	while (i < size)
	{
		j = i - 1;
		while (array[i] > array[j])
		{
			i++;
			j++;
		}
		if (i < size && array[j] > array[i])
		{
			while (j > 0 && array[i] < array[j - 1])
				j--;
			tmp = i;
			tmp2 = array[i];
			while (i > j)
			{
				array[i] = array[i - 1];
				i--;
			}
			array[j] = tmp2;
			i = tmp;
		}
		i++;
	}
	return (array);
}

// void	sort_array(t_infos *infos)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	int				tmp;
// 	int				tmp2;

// 	i = 1;
// 	fill_array(infos);
// 	while (i < infos->size)
// 	{
// 		j = i - 1;
// 		while (infos->array[i] > infos->array[j])
// 		{
// 			i++;
// 			j++;
// 		}
// 		if (infos->array[j] > infos->array[i])
// 		{
// 			while (j > 0 && infos->array[i] < infos->array[j - 1])
// 				j--;
// 			tmp = i;
// 			tmp2 = infos->array[i];
// 			while (i > j)
// 			{
// 				infos->array[i] = infos->array[i - 1];
// 				i--;
// 			}
// 			infos->array[j] = tmp2;
// 		}
// 		i = tmp + 1;
// 	}
// 	for (unsigned int k = 0; k < infos->size; k++)
// 		printf("%d\n", infos->array[k]);
// }
