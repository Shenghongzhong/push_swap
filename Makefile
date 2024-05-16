# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/05/16 15:43:20 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -g
SRCS	:=	\
		src/push_swap.c \
		src/utils/operation.c

LIBFT_PATH	:=	./libft
INCLUDE		:=	-I ./inc -I ./libft/inc
OBJS		:=	$(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L $(LIBFT_PATH) -lft

%.o: %.c
	$(CC) $(INCLUDE) $(LIBC_INC) -c $< -o $@
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all
