/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:19:03 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/28 18:20:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_sorted_list_reverse(t_elem *first)
{
	t_elem	*tmp;
	int		previous;

	if (!first)
		return (0);
	tmp = first;
	previous = first->nb;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		if (tmp->nb > previous)
			return (0);
		previous = tmp->nb;
	}
	return (1);
}

int		check_sorted_list(t_elem *first)
{
	t_elem	*tmp;
	int		previous;

	if (!first)
		return (0);
	tmp = first;
	previous = first->nb;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		if (tmp->nb < previous)
			return (0);
		previous = tmp->nb;
	}
	return (1);
}

int		check_sorted(t_infos *infos)
{
	if (infos->b)
		return (0);
	if (!check_sorted_list(infos->first_a))
		return (0);
	return (1);
}

int		check_instruction(char *instruction, t_infos *infos)
{
	int	i;

	i = 0;
	while (i < NB_INSTRU)
	{
		if (!ft_strcmp(instruction, infos->instructions[i]))
		{
			infos->op[i](infos);
			return (0);
		}
		i++;
	}
	return (1);
}

void	wait_instructions(t_infos *infos)
{
	char	*instruction;

	while ((get_next_line(STDIN_FILENO, &instruction)) > 0)
	{
		if (check_instruction(instruction, infos))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(instruction);
	}
	free(instruction);
	if (check_sorted(infos))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
