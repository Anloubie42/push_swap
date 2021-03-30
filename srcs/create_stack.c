/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:10:40 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/30 12:11:21 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_operations(t_infos *infos)
{
	infos->op[0] = swap_a;
	infos->op[1] = swap_b;
	infos->op[2] = swap_both;
	infos->op[3] = push_a;
	infos->op[4] = push_b;
	infos->op[5] = rotate_a;
	infos->op[6] = rotate_b;
	infos->op[7] = rotate_both;
	infos->op[8] = reverse_ra;
	infos->op[9] = reverse_rb;
	infos->op[10] = reverse_rboth;
}

void	fill_instructions(t_infos *infos)
{
	int	i;

	i = -1;
	infos->instructions[0] = ft_strdup("sa");
	infos->instructions[1] = ft_strdup("sb");
	infos->instructions[2] = ft_strdup("ss");
	infos->instructions[3] = ft_strdup("pa");
	infos->instructions[4] = ft_strdup("pb");
	infos->instructions[5] = ft_strdup("ra");
	infos->instructions[6] = ft_strdup("rb");
	infos->instructions[7] = ft_strdup("rr");
	infos->instructions[8] = ft_strdup("rra");
	infos->instructions[9] = ft_strdup("rrb");
	infos->instructions[10] = ft_strdup("rrr");
	while (++i < NB_INSTRU)
		if (!infos->instructions[i])
			free_exit(infos, 1);
	fill_operations(infos);
}

void	create_stack(int ac, char **av, t_infos *infos)
{
	unsigned int	i;

	infos->a = new_elem(ft_atoi(av[1]), 0);
	infos->b = NULL;
	infos->instructions = (char**)malloc(sizeof(char *) * NB_INSTRU);
	infos->sorted = 0;
	if (!(infos->a) || !(infos->instructions))
		free_exit(infos, 1);
	i = 2;
	infos->size = ac - 1;
	infos->size_a = 1;
	infos->size_b = 0;
	while (i <= infos->size)
	{
		add_elem_back(&infos->a, new_elem(ft_atoi(av[i]), i - 1));
		infos->size_a++;
		i++;
	}
	infos->first_a = infos->a;
	fill_instructions(infos);
}
