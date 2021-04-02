/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:03:07 by antoine           #+#    #+#             */
/*   Updated: 2021/04/02 12:13:15 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_elem	*push_elem(t_elem **alst1, t_elem **alst2)
{
	t_elem	*tmp;

	if (!alst1 || !(*alst1))
		return (NULL);
	tmp = (*alst1)->next;
	(*alst1)->next = (*alst2);
	(*alst2) = (*alst1);
	(*alst1) = tmp;
	return (*alst1);
}

void	push_a(t_infos *infos)
{
	if (infos->size_b >= 1)
	{
		infos->first_b = push_elem(&infos->b, &infos->a);
		infos->first_a = infos->a;
		infos->size_a += 1;
		infos->size_b -= 1;
	}
}

void	push_b(t_infos *infos)
{
	if (infos->size_a >= 1)
	{
		infos->first_a = push_elem(&infos->a, &infos->b);
		infos->first_b = infos->b;
		infos->size_a -= 1;
		infos->size_b += 1;
	}
}
