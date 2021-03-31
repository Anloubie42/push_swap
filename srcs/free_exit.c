/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:30:56 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/31 08:59:45 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_elem *list)
{
	t_elem	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_exit(t_infos *infos, int ex)
{
	int		i;

	i = 0;
	while (infos->instructions[i] && i < NB_INSTRU)
		free(infos->instructions[i++]);
	if (infos->instructions)
		free(infos->instructions);
	free_list(infos->a);
	free_list(infos->b);
	if (infos)
		free(infos);
	if (ex == 1)
		exit(1);
}
