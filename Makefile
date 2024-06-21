# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/06/21 20:20:03 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colour
DF = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
MAGENTA = \033[0;95m
YELLOW = \033[0;93m
CYAN =\033[0;96m
WHITE = \033[0;97m
BOLD = \033[91m

# Project variables
NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -pedantic -g #-fsanitize=leak
SRC_DIR	:=	./src
SRCS	:=	\
		push_swap.c \
		utils/ps_stack.c \
		utils/stack_operations.c \
		utils/init_stack.c \
		utils/stack_swap.c \
		utils/psop_uniq.c \
		utils/psop_match.c \
		utils/sort_tiny.c \
		utils/error_handler.c \
		utils/sort_big_numbers/sort_big.c \
		utils/sort_big_numbers/cfg_nodes.c \
		utils/sort_big_numbers/ps_nodes.c \
		utils/sort_small_numbers/sort_small.c \
		utils/sort_small_numbers/case_a.c \
		utils/sort_small_numbers/case_b.c \
		utils/sort_small_numbers/case_c.c \
		utils/sort_small_numbers/case_d.c \
		utils/sort_small_numbers/case_e.c 


LIBFT_PATH	:=	./libft
INCLUDE		=	-I ./inc -I $(LIBFT_PATH)/inc
LDFLAGS		:=	-L$(LIBFT_PATH) -lft
OBJS		:=	$(patsubst %c, %o, $(SRCS))
OBJS_DIR	:=	./obj
NOPRINTMAKE	:= 	--no-print-directory 

all:$(NAME)

$(NAME):$(addprefix $(OBJS_DIR)/, $(OBJS)) | LIBFT
	@$(CC) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $(NAME) $(LDFLAGS)
	@echo "$(YELLOW)[PUSH_SWAP] $(GREEN)Build completed!$(DF)"

LIBFT:
	@make $(NOPRINTMAKE) -C $(LIBFT_PATH) all

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) -c $< -o $@

clean:
	@make $(NOPRINTMAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make $(NOPRINTMAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "$(YELLOW)[PUSH_SWAP] $(GREEN)Objects Removed$(DF)"
	@echo "$(MAGENTA)Project Reset Ready$(DF)"

re:	fclean all

# Test Section
N	?= 5

checker:
	@ARG=$$(shuf -i 1-10000 -n $(N) | tr '\n' ' '); \
	echo "$(CYAN)ARG generated: $(YELLOW)$$ARG$(DF)"; \
	echo "$(YELLOW)Running test with the checker$(DF)";\
	./push_swap $$ARG | ./checker_linux $$ARG

test:
	@shuf -i 1-10000 -n $(N) | xargs ./push_swap

val:
	@ARG=$$(shuf -i 1-100000 -n $(N) | tr '\n' ' '); \
	echo "ARG generated: $$ARG"; \
	(valgrind --leak-check=full ./push_swap $$ARG > /dev/null) 2>&1


.PHONY: all clean fclean re checker test val
