/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:03:23 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 13:48:30 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_elem		*reverse_rotate_stack(t_elem **alst)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = (*alst);
	tmp2 = tmp;
	while ((*alst)->next)
		(*alst) = (*alst)->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	(*alst)->next = tmp;
	return (*alst);
}

void		reverse_ra(t_infos *infos)
{
	infos->first_a = reverse_rotate_stack(&infos->a);
}

void		reverse_rb(t_infos *infos)
{
	infos->first_b = reverse_rotate_stack(&infos->b);
}

void		reverse_rboth(t_infos *infos)
{
	reverse_ra(infos);
	reverse_rb(infos);
}
