/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:07:08 by antoine           #+#    #+#             */
/*   Updated: 2021/03/14 11:08:45 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ra(t_infos *infos)
{
	rotate_a(infos);
	write(1, "ra\n", 3);
}

void	print_rb(t_infos *infos)
{
	rotate_b(infos);
	write(1, "rb\n", 3);
}

void	print_rotate_both(t_infos *infos)
{
	print_ra(infos);
	print_rb(infos);
}
