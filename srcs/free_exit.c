/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:30:56 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 11:50:30 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		free_list(t_elem *list)
{
	t_elem	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void		free_exit(t_infos *infos)
{
	int		i;

	i = 0;
	while (i < NB_INSTRU)
		free(infos->instructions[i++]);
	free(infos->instructions);
	free_list(infos->a);
	free_list(infos->b);
	free(infos);
	exit(0);
}
