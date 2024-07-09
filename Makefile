# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 15:16:33 by mtrullar          #+#    #+#              #
#    Updated: 2024/07/09 14:10:35 by mtrullar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME		=	pushswap
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3

#Folders
INCLUDE		=	incs/
SRCS_DIR	=	srcs/
LIBFT		= 	libft/
OBJ_DIR		=	obj/

RM			=	@rm -rf

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILE =	list_func/basic_func.c			\
			parsing/check_requirements.c	\
			swap_func/composed_swap.c		\
			swap_func/swap.c 				\
			algo/sort_algo.c				\
			main.c							\

SRCS		= $(addprefix $(SRCS_DIR), $(SRC_FILE))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))


OBJF		=	.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) -I$(INCLUDE) $(OBJ) -Llibft -lcustomft
	@echo "$(GREEN)\e[1mPUSH_SWAP COMPILED!\e[0m$(DEF_COLOR)"
	
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)\e[1mPUSH_SWAP compiling:\e[0m $< $(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/list_func
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/swap_func
	@mkdir -p $(OBJ_DIR)/algo

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Executable destroyed!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)\e[1mEverything has been rebuilt, fresh and clean\e[0m$(DEF_COLOR)"

.PHONY: all clean fclean re