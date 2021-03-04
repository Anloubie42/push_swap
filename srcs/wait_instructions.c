/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:19:03 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 13:53:40 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_instruction(char *instruction, t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < NB_INSTRU)
	{
		if (!ft_strcmp(instruction, stacks->instructions[i]));
			return (0);
		i++;
	}
	return (1);
}

void	wait_instructions(t_stack *stacks)
{
	char	*instruction;

	printf("%d\n", stacks->stack_a[0]);
	while ((get_next_line(STDIN_FILENO, &instruction)) > 0)
	{
		if (check_instruction(instruction, stacks))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		// write(1, instruction, ft_strlen(instruction));
		// write(1, "\n", 1);
	}
}
