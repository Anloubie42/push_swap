/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:53:12 by antoine           #+#    #+#             */
/*   Updated: 2021/03/05 08:58:07 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_front_elem(t_elem **alst)
{
	t_elem	*tmp;

	if (!((*alst)->next))
		return ;
	tmp = (*alst)->next;
	(*alst)->next = (*alst)->next->next;
	tmp->next = (*alst);
}

void	add_elem_front(t_elem **alst, t_elem *new)
{
	t_elem	*temp;

	if (!alst)
		return ;
	temp = *alst;
	*alst = new;
	new->next = temp;
}

void	add_elem_back(t_elem **alst, t_elem *new)
{
	t_elem	*temp;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_elem	*new_elem(int nb, unsigned int place)
{
	t_elem	*new;

	new = (t_elem*)malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->place = place;
	new->next = NULL;
	return (new);
}
