/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:02:26 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 19:50:31 by antoine          ###   ########.fr       */
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
	t_elem			*a;
	t_elem			*b;
	t_elem			*first;
}					t_infos;

void				create_stack(int ac, char **av);
void				wait_instructions(t_elem *stacks);

#endif
