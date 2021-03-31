/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:43:33 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/31 09:16:34 by anloubie         ###   ########.fr       */
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
**	Blocs
*/
t_bloc				*new_bloc(void);
void				add_bloc_front(t_bloc **alst, t_bloc *new);
void				free_front_bloc(t_bloc **alst);

/*
**	Sort
*/
void				begin_sort(t_infos *infos);
void				sort_three_a(t_infos *infos);
void				sort_five(t_infos *infos);
int					*sort_array(int *array, unsigned int size);
void				sort_three(t_infos *infos);
void				split_stack_a(t_infos *infos, t_bloc **bloc_a, t_bloc **b);
void				split_stack_b(t_infos *infos, t_bloc **bloc_a, t_bloc **b);

/*
**	Checks
*/
int					check_sorted_list(t_elem *first);
int					check_sorted_list_reverse(t_elem *first);

/*
**	Median
*/
int					get_median_list(t_infos *infos, t_elem *first,
					unsigned int size);

/*
**	Print functions
*/
void				print_pa(t_infos *infos);
void				print_pb(t_infos *infos);
void				print_sa(t_infos *infos);
void				print_sb(t_infos *infos);
void				print_swap_both(t_infos *infos);
void				print_ra(t_infos *infos);
void				print_rb(t_infos *infos);
void				print_rotate_both(t_infos *infos);
void				print_rra(t_infos *infos);
void				print_rrb(t_infos *infos);
void				print_rerverse_rboth(t_infos *infos);

/*
**	Free
*/
void				free_blocs(t_bloc *bloc);

#endif
