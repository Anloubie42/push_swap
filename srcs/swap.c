/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:56 by antoine           #+#    #+#             */
/*   Updated: 2021/04/02 12:14:28 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_elem	*swap_front_elem(t_elem **alst)
{
	t_elem	*tmp;

	if (!alst || !(*alst))
		return (NULL);
	if (!((*alst)->next))
		return (*alst);
	tmp = (*alst)->next;
	(*alst)->next = (*alst)->next->next;
	tmp->next = (*alst);
	(*alst) = tmp;
	return (*alst);
}

void	swap_a(t_infos *infos)
{
	if (infos->size_a >= 2)
		infos->first_a = swap_front_elem(&infos->a);
}

void	swap_b(t_infos *infos)
{
	if (infos->size_b >= 2)
		infos->first_b = swap_front_elem(&infos->b);
}

void	swap_both(t_infos *infos)
{
	swap_a(infos);
	swap_b(infos);
}
