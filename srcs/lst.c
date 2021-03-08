/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:53:12 by antoine           #+#    #+#             */
/*   Updated: 2021/03/07 15:15:44 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_element_by_id(t_elem *elem, unsigned int index)
{
	t_elem	*tmp;

	tmp = elem;
	while (tmp->place != index && tmp->next)
		tmp = tmp->next;
	if (!tmp->next && tmp->place < index)
		return (-1);
	else
		return (tmp->nb);
}

t_elem	*find_last_elem(t_elem *first)
{
	t_elem	*tmp;

	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
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
