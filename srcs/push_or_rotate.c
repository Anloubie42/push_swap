/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 08:54:25 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/16 08:20:31 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_or_rotate_first(t_infos *infos, int median)
{
	if (infos->first_a->nb < median)
	{
		print_pb(infos);
		b->size++;
	}
	else
		print_ra(infos);
}
