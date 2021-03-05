/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:02:26 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/05 09:01:38 by anloubie         ###   ########.fr       */
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

typedef struct		s_infos t_infos;

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
	void			(*op)(t_elem *stacks);
	unsigned int	size;
	t_elem			*first_a;
	t_elem			*first_b;
}					t_infos;

void				create_stack(int ac, char **av);
void				wait_instructions(t_infos *infos);
void				add_elem_front(t_elem **alst, t_elem *new);
void				add_elem_back(t_elem **alst, t_elem *new);
t_elem				*new_elem(int nb, unsigned int place);
void				swap_front_elem(t_elem **alst);

#endif
