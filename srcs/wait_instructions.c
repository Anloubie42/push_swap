/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:19:03 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 09:08:16 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_instruction(char *instruction, t_infos *infos)
{
	int	i;

	i = 0;
	while (i < NB_INSTRU)
	{
		if (!ft_strncmp(instruction, infos->instructions[i], ft_strlen(infos->instructions[i])))
			return (0);
		i++;
	}
	return (1);
}

void	wait_instructions(t_infos *infos)
{
	char	*instruction;
	t_elem	*tmp;

	tmp = infos->first_a;
	while (1)
	{
		printf("%d\n", tmp->nb);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	printf("###########################\n\n");
	swap_front_elem(&infos->a);
	tmp = infos->first_a;
	while (1)
	{
		printf("%d\n", tmp->nb);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	while ((get_next_line(STDIN_FILENO, &instruction)) > 0)
	{
		if (check_instruction(instruction, infos))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		free(instruction);
	}
}
