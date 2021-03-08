# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:12:09 by anloubie          #+#    #+#              #
#    Updated: 2021/03/05 19:50:02 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		push_swap
NAME_2	=		checker

# Sources

SRCS_2_NAME	=	create_stack.c			\
				wait_instructions.c		\
				lst.c					\
				push.c					\
				swap.c					\
				rotate.c				\
				reverse_rotate.c		\
				free_exit.c				\
				error_check.c			\
				main_checker.c

SRCS_NAME	=	create_stack.c			\
				wait_instructions.c		\
				lst.c					\
				push.c					\
				swap.c					\
				rotate.c				\
				reverse_rotate.c		\
				free_exit.c				\
				error_check.c			\
				check_list.c			\
				sort.c					\
				main_swap.c
				# main_checker.c

INCS_NAME	=	checker.h

LIB_NAME	=	libft.a

# Directories

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR	=	./includes/
LIB_DIR		=	./libft/
CHECK_MAIN	=	main_checker.c
SWAP_MAIN	=	main_swap.c

# Files

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
SRCS_2		=	$(addprefix $(SRCS_DIR), $(SRCS_2_NAME))
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_2		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_2))
INCS		=	$(addprefix $(INCS_DIR), $(INCS_NAME))
LIB			=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# Compilation

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -I $(INCS_DIR)
LIBH		=	-I $(LIB_DIR)includes/

all: $(NAME) $(NAME_2)

$(LIB):
	@make -j -sC $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[32;01m[$(NAME) OK]\033[00m"

$(NAME_2): $(LIB) $(OBJS_2)
	@$(CC) $(OBJS_2) $(LIB) -o $(NAME_2)
	@echo "\033[32;01m[$(NAME_2) OK]\033[00m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIBH) -o $@ -c $<

librm:
	@make -sC $(LIB_DIR) fclean

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIB_DIR) clean

fclean: librm clean
	@rm -f $(NAME)
	@echo "\033[32;01m[$(NAME) fclean OK]\033[00m"

re: fclean all

.PHONY: all librm clean fclean re
