/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:33 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/12 15:22:32 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

typedef struct		s_bloc
{
	size_t			size;
	struct s_bloc	*next;
}					t_bloc;

/*
**	Print lists
*/
void				print_list(t_elem *elem);

/*
**	List
*/
t_elem				*find_last_elem(t_elem *first);
int					get_element_by_id(t_elem *elem, unsigned int index);
void				add_bloc_front(t_bloc **alst, t_bloc *new);
t_bloc				*new_bloc(void);
void				free_front_bloc(t_bloc **alst);

/*
**	Sort
*/
void				begin_sort(t_infos *infos);
void				sort_three(t_infos *infos, t_elem *first, size_t size);
int					*sort_array(int *array, unsigned int size);
void				fill_array(t_infos *infos);
void				push_or_rotate_first(t_infos *infos, t_elem *first);

/*
**	Checks
*/
int					is_first_biggest(t_elem *elem);
int					is_last_biggest(t_elem *elem);
int					is_first_smallest(t_elem *elem);
int					is_last_smallest(t_elem *elem);
int					check_sorted_list(t_elem *first);
int					check_sorted_list_reverse(t_elem *first);

/*
**	Median
*/
int					get_median_list(t_elem *first, unsigned int size);

#endif
