# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/06/11 16:04:07 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -pedantic -g #-fsanitize=leak
SRC_DIR	:=	./src
SRCS	:=	\
		push_swap.c \
		utils/operation.c \
		utils/stack.c \
		utils/operations_dblst.c \
		utils/stack_dblst.c \
		utils/stack_swap.c \
		utils/rank_stack.c \
		utils/psop_uniq.c \
		utils/psop_match.c \
		utils/sort_three.c \
		utils/stack_utils.c \
		utils/sort_five.c

LIBFT_PATH	:=	./libft
INCLUDE		=	-I ./inc -I $(LIBFT_PATH)/inc
LDFLAGS		:=	-L $(LIBFT_PATH) -lft
OBJS		:=	$(patsubst %c, %o, $(SRCS))
OBJS_DIR	:=	./obj

all:$(NAME)

$(NAME):  $(addprefix $(OBJS_DIR)/, $(OBJS))
	@$(CC) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $(NAME) $(LDFLAGS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE) -c $< -o $@
clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "All is cleaned"

re:	fclean all

N	:= 10
test:
	@echo "Running tests..."
	@./push_swap $(shell shuf -i 1-5000 -n $(N))

.PHONY: all clean fclean re
