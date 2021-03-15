/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:03:19 by antoine           #+#    #+#             */
/*   Updated: 2021/03/14 11:03:33 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pa(t_infos *infos)
{
	push_a(infos);
	write(1, "pa\n", 3);
}

void	print_pb(t_infos *infos)
{
	push_b(infos);
	write(1, "pb\n", 3);
}
