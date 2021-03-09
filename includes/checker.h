/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:02:26 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/09 08:48:17 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define NB_INSTRU 11

typedef struct		s_elem
{
	int				nb;
	unsigned int	place;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_infos
{
	t_elem			*a;
	t_elem			*b;
	int				sorted;
	char			**instructions;
	void			(*op[NB_INSTRU])(struct s_infos *infos);
	unsigned int	size;
	t_elem			*first_a;
	t_elem			*first_b;
	int				*array;
}					t_infos;

/*
**	Initialization
*/
void				create_stack(int ac, char **av, t_infos *infos);
void				wait_instructions(t_infos *infos);

/*
**	List functions
*/
void				add_elem_front(t_elem **alst, t_elem *new);
void				add_elem_back(t_elem **alst, t_elem *new);
t_elem				*new_elem(int nb, unsigned int place);

/*
**	Swap
*/
t_elem				*swap_front_elem(t_elem **alst);
void				swap_a(t_infos *infos);
void				swap_b(t_infos *infos);
void				swap_both(t_infos *infos);

/*
**	Push
*/
t_elem				*push_elem(t_elem **alst1, t_elem **alst2);
void				push_a(t_infos *infos);
void				push_b(t_infos *infos);

/*
**	Rotate
*/
t_elem				*rotate_stack(t_elem **alst);
void				rotate_a(t_infos *infos);
void				rotate_b(t_infos *infos);
void				rotate_both(t_infos *infos);

/*
**	Reverse rotate
*/
t_elem				*reverse_rotate_stack(t_elem **alst);
void				reverse_ra(t_infos *infos);
void				reverse_rb(t_infos *infos);
void				reverse_rboth(t_infos *infos);

/*
**	Free
*/
void				free_exit(t_infos *infos);

/*
**	Error check
*/
int					input_error(int ac, char **av);

/*
**	Sort check
*/
int					check_sorted(t_infos *infos);

#endif
