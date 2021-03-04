/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:10:40 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 14:02:19 by anloubie         ###   ########.fr       */
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
	t_stack	*stacks;

	stacks = (t_stack*)malloc(sizeof(t_stack));
	if (!stacks)
		return ;
	stacks->stack_a = (int*)malloc(sizeof(int) * ac);
	stacks->stack_b = (int*)malloc(sizeof(int) * ac);
	stacks->instructions = (char**)malloc(sizeof(char *) * NB_INSTRU);
	stacks->sorted = 0;
	if (!(stacks->stack_a) || !(stacks->stack_b) || !(stacks->instructions))
		return ;
	i = ac;
	while (--i > 0)
		stacks->stack_a[i] = ft_atoi(av[i]);
	fill_instructions(stacks);
	wait_instructions(stacks);
}
