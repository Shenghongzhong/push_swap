# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/06/20 13:54:21 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -pedantic -g #-fsanitize=leak
SRC_DIR	:=	./src
SRCS	:=	\
		push_swap.c \
		utils/operation.c \
		utils/stack.c \
		utils/ft_dblst.c \
		utils/operations_dblst.c \
		utils/stack_dblst.c \
		utils/stack_swap.c \
		utils/rank_stack.c \
		utils/psop_uniq.c \
		utils/psop_match.c \
		utils/sort_three.c \
		utils/stack_utils.c \
		utils/input_valid.c \
		utils/error_handler.c \
		utils/sort_big.c \
		utils/sort_five/sort_five.c \
		utils/sort_five/case_a.c \
		utils/sort_five/case_b.c \
		utils/sort_five/case_c.c \
		utils/sort_five/case_d.c \
		utils/sort_five/case_e.c 


LIBFT_PATH	:=	./libft
INCLUDE		=	-I ./inc -I $(LIBFT_PATH)/inc
LDFLAGS		:=	-L $(LIBFT_PATH) -lft
OBJS		:=	$(patsubst %c, %o, $(SRCS))
OBJS_DIR	:=	./obj

all:$(NAME)

$(NAME):  $(addprefix $(OBJS_DIR)/, $(OBJS))
	@$(CC) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $(NAME) $(LDFLAGS)
	@echo "Build completed"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) -c $< -o $@
clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "All is cleaned"

re:	fclean all

N	?= 5
test:
	@ARG=$$(shuf -i 1-10000 -n $(N) | tr '\n' ' '); \
	echo "ARG generated: $$ARG"; \
	echo "Running test with the checker";\
	./push_swap $$ARG | ./checker_linux $$ARG

check:
	@shuf -i 1-10000 -n $(N) | xargs ./push_swap

.PHONY: all clean fclean re
