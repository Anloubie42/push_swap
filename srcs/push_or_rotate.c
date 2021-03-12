/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 08:54:25 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/12 08:58:24 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_or_rotate_first(t_infos *infos, t_elem *first)
{
	if (infos->first_a->nb >= infos->median)
		rotate_a(infos);
	else
		push_b(infos);
}
