/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:11:51 by antoine           #+#    #+#             */
/*   Updated: 2021/03/14 11:13:56 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rra(t_infos *infos)
{
	reverse_ra(infos);
	write(1, "rra\n", 4);
}

void	print_rrb(t_infos *infos)
{
	reverse_rb(infos);
	write(1, "rrb\n", 4);
}

void	print_reverse_rboth(t_infos *infos)
{
	print_rra(infos);
	print_rrb(infos);
}
