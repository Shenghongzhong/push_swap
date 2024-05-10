# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 14:29:39 by szhong            #+#    #+#              #
#    Updated: 2024/05/10 18:20:31 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
CC	:=	cc -Wall -Werror -Wextra -g
SRCS	:=	\
		src/push_swap.c

LIBFT_PATH	:=	./libft
LIBFT_INC	:=	./libft/inc
INCLUDE		:=	-I
OBJS		:=	push_swap.o
all:$(NAME)

$(NAME):
	$(CC) -c $(SRCS) -o $(OBJS) $(INCLUDE) $(LIBFT_INC) 
	$(CC) $(OBJS) -o $(NAME) -L $(LIBFT_PATH) -lft

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all
