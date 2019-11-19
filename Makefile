# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:17:47 by dheredat          #+#    #+#              #
#    Updated: 2019/11/19 18:39:42 by dheredat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_PS			=	push_swap
NAME_CH			=	checker

LIBFT_DIR	=	./ft_printf
SRC_DIR		=	./src
INC_DIR		=	./inc
OBJ_DIR		=	./obj

FLAGS	=	-Wall -Wextra -Werror

PS_H	=	$(INC_DIR)/push_swap.h

SRC	=	ch_act.c ch_act2.c ch_act3.c\
		nbrs_check.c nbrs_valid.c\
		tails.c\
		solution.c price.c sort.c\
		visualizer.c visualizer2.c\
		visualizer3.c visualizer4.c

SRC_T		=	$(addprefix $(SRC_DIR)/,$(SRC))

CHECKER		=	checker.c
PUSH_SWAP	=	push_swap.c

OBJS			=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
PUSH_SWAP_OBJ	=	$(OBJ_DIR)/push_swap.o
CHECKER_OBJ		=	$(OBJ_DIR)/checker.o
LIBFT			=	$(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C ft_printf

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(PS_H)
	@echo "\033[35mCompiling ./push_swap\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(PUSH_SWAP_OBJ) -o $(NAME_PS)
	@echo "\033[35mCompiling ./checker\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(CHECKER_OBJ) -o $(NAME_CH)
	@echo "\033[1;32mProject was built\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ft_printf clean

fclean: clean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CH)
	@make -C ft_printf fclean
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all
