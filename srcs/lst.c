/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:53:12 by antoine           #+#    #+#             */
/*   Updated: 2021/03/04 19:56:52 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_elem(t_elem **alst, t_elem *new)
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
	while (temp && temp->next)
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
