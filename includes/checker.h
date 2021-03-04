/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:02:26 by anloubie          #+#    #+#             */
/*   Updated: 2021/03/04 13:56:19 by anloubie         ###   ########.fr       */
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

typedef struct		s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				sorted;
	char			**instructions;
	void			(*op)(t_stack *stacks);
}					t_stack;

void				create_stack(int ac, char **av);
void				wait_instructions(t_stack *stacks);

#endif
