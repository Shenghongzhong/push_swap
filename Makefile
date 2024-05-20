# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/05/20 16:44:48 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -g
SRC_DIR	:=	./src
SRCS	:=	\
		push_swap.c \
		utils/operation.c \
		utils/stack.c

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

test:
	@echo "Running tests..."
	@./push_swap $(shell  shuf -i 1-5000 -n 10)

.PHONY: all clean fclean re
