/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:03:42 by antoine           #+#    #+#             */
/*   Updated: 2021/03/14 11:06:22 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sa(t_infos *infos)
{
	swap_a(infos);
	write(1, "sa\n", 3);
}

void	print_sb(t_infos *infos)
{
	swap_b(infos);
	write(1, "sb\n", 3);
}

void	print_swap_both(t_infos *infos)
{
	print_sa(infos);
	print_sb(infos);
}
