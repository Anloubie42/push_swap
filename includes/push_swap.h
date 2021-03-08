/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:33 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/07 14:18:22 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

/*
**	Print lists
*/
void		print_list(t_elem *elem);

/*
**	List
*/
t_elem		*find_last_elem(t_elem *first);
int			get_element_by_id(t_elem *elem, unsigned int index);

/*
**	Sort
*/
void		begin_sort(t_infos *infos);
void		sort_three(t_infos *infos);

/*
**	Checks
*/
int			is_first_biggest(t_elem *elem);
int			is_last_biggest(t_elem *elem);
int			is_first_smallest(t_elem *elem);
int			is_last_smallest(t_elem *elem);

#endif
