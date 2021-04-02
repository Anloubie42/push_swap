/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:45:59 by anloubie          #+#    #+#             */
/*   Updated: 2021/04/02 12:06:19 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_elem	*rotate_stack(t_elem **alst)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = (*alst)->next;
	tmp2 = (*alst);
	(*alst)->next = NULL;
	(*alst) = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	return (*alst);
}

void	rotate_a(t_infos *infos)
{
	if (infos->size_a > 1)
		infos->first_a = rotate_stack(&infos->a);
}

void	rotate_b(t_infos *infos)
{
	if (infos->size_b > 1)
		infos->first_b = rotate_stack(&infos->b);
}

void	rotate_both(t_infos *infos)
{
	rotate_a(infos);
	rotate_b(infos);
}
