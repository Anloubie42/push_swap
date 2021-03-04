# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:12:09 by anloubie          #+#    #+#              #
#    Updated: 2021/03/04 13:20:12 by anloubie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		checker

# Sources

SRCS_NAME	=	main.c					\
				create_stack.c			\
				wait_instructions.c

INCS_NAME	=	checker.h

LIB_NAME	=	libft.a

# Directories

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR	=	./includes/
LIB_DIR		=	./libft/

# Files

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
INCS		=	$(addprefix $(INCS_DIR), $(INCS_NAME))
LIB			=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# Compilation

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -I $(INCS_DIR)
LIBH		=	-I $(LIB_DIR)includes/

all: $(NAME)

$(LIB):
	@make -j -sC $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[32;01m[$(NAME) OK]\033[00m"

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
