#!/bin/bash

rm -rf app
clear


cc -Wall -Werror -Wextra -c ./main.c -I ../../inc -I ../../libft/inc -o main.o
##cc -Wall -Werror -Wextra -c ../../src/utils/operations_dblst.c -I ../../inc -o operations_dblst.o
##cc -Wall -Werror -Wextra -c ../../src/utils/stack_dblst.c  -I ../../inc -o stack_dblst.o
#cc -Wall -Werror -Wextra -c ./tests.c -I ../../inc -I ../../libft/inc -o tests.o
#cc -Wall -Werror -Wextra main.o ../../libft/libft.a tests.o -o app
##cc -Wall -Werror -Wextra main.o ../../libft/libft.a stack_dblst.o operations_dblst.o -o app
cc -Wall -Werror -Wextra main.o ../../libft/libft.a  -o app
./app
