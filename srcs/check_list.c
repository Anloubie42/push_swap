/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:35:15 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/30 00:14:44 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_last_biggest(t_elem *elem)
{
	t_elem	*tmp;
	int		nb;

	tmp = elem;
	if (!tmp || !tmp->next)
		return (0);
	nb = tmp->nb;
	while (tmp->next->next)
	{
		if (tmp->nb > nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	if (nb < tmp->next->nb)
		return (1);
	return (0);
}

int	is_last_smallest(t_elem *elem)
{
	t_elem	*tmp;
	int		nb;

	tmp = elem;
	if (!tmp || !tmp->next)
		return (0);
	nb = tmp->nb;
	while (tmp->next->next)
	{
		if (tmp->nb < nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	if (nb > tmp->next->nb)
		return (1);
	return (0);
}

int	is_first_biggest(t_elem *elem)
{
	t_elem	*tmp;
	int		first;

	tmp = elem;
	if (tmp)
	{
		first = tmp->nb;
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->nb > first)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int	is_first_smallest(t_elem *elem)
{
	t_elem	*tmp;
	int		first;

	tmp = elem;
	if (tmp)
	{
		first = tmp->nb;
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->nb < first)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
