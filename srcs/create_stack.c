/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:10:40 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 19:46:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_instructions(t_stack *stacks)
{
	stacks->op[0] = "sa";
	stacks->op[1] = "sb";
	stacks->op[2] = "ss";
	stacks->op[3] = "pa";
	stacks->op[4] = "pb";
	stacks->op[5] = "ra";
	stacks->op[6] = "rb";
	stacks->op[7] = "rr";
	stacks->op[8] = "rra";
	stacks->op[9] = "rrb";
	stacks->op[10] = "rrr";
}

void	fill_instructions(t_stack *stacks)
{
	stacks->instructions[0] = "sa";
	stacks->instructions[1] = "sb";
	stacks->instructions[2] = "ss";
	stacks->instructions[3] = "pa";
	stacks->instructions[4] = "pb";
	stacks->instructions[5] = "ra";
	stacks->instructions[6] = "rb";
	stacks->instructions[7] = "rr";
	stacks->instructions[8] = "rra";
	stacks->instructions[9] = "rrb";
	stacks->instructions[10] = "rrr";
	fill_operations(stacks);
}

void	create_stack(int ac, char **av)
{
	int 	i;
	t_infos	*infos;
	t_stack	*it;

	infos = (t_infos*)malloc(sizeof(t_infos));
	if (!infos)
		return ;
	infos->a = (t_stack*)malloc(sizeof(t_stack));
	infos->b = (t_stack*)malloc(sizeof(t_stack));
	infos->instructions = (char**)malloc(sizeof(char *) * NB_INSTRU);
	infos->sorted = 0;
	if (!(infos->a) || !(infos->b) || !(infos->instructions))
		return ;
	i = ac;
	infos->size = ac;
	while (--i > 0)
	{
		infos->a->nb = ft_atoi(av[i]);
		infos->a->place = i;
		infos->a->next = (t_stack*)malloc(sizeof(t_stack));
		if (!infos->a->next)
			return ;i
	}
	fill_instructions(infos);
	wait_instructions(infos);
}
