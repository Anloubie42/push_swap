/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:56 by antoine           #+#    #+#             */
/*   Updated: 2021/03/04 15:07:52 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stacks)
{
	int	tmp;

	if (stacks->size <= 1 || !stacks->stack_a[stacks->size] || !stacks->stack_a[stacks->size - 1])
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
}

void	sb(t_stack *stacks)
{
	int	tmp;

	if (stacks->size <= 1 || !stacks->stack_b[0] || !stacks->stack_b[1])
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
}

void	sr(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
}
