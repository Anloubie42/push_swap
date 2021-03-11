/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:33 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/11 11:24:44 by antoine          ###   ########.fr       */
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
int			*sort_array(int *array, unsigned int size);
void		fill_array(t_infos *infos);

/*
**	Checks
*/
int			is_first_biggest(t_elem *elem);
int			is_last_biggest(t_elem *elem);
int			is_first_smallest(t_elem *elem);
int			is_last_smallest(t_elem *elem);
int			check_sorted_list(t_elem *first);

#endif
