/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:26:15 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/12 15:22:26 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_front_bloc(t_bloc **bloc)
{
	t_bloc *tmp;

	if (*bloc)
	{
		tmp = (*bloc);
		if ((*bloc)->next)
			(*bloc) = (*bloc)->next;
		else
			(*bloc) = NULL;
		free(tmp);
	}
}

void	add_bloc_front(t_bloc **alst, t_bloc *new)
{
	t_bloc	*temp;

	if (!alst)
		return ;
	temp = *alst;
	*alst = new;
	new->next = temp;
}

t_bloc	*new_bloc(void)
{
	t_bloc	*new;

	new = (t_bloc*)malloc(sizeof(t_bloc));
	if (!new)
		return (NULL);
	new->size = 0;
	new->next = NULL;
	return (new);
}
