# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:11:20 by svalente          #+#    #+#              #
#    Updated: 2023/09/11 16:37:29 by svalente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
EXTRA_FLAGS = -pthread
RM = rm -f

#$(VERBOSE).SILENT:

HEADER = philo.h

INC = ./includes
CFLAGS = -Wall -Werror -Wextra -I$(INC) -g -fsanitize=address

SRC_PATH = ./srcs

OBJ_PATH = ./objs

SRC_NAME =	check_arguments.c			\
			utils.c						\
			main.c						\
			time.c						\
			start.c 					\
			routine.c					\
			global.c 					\

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(EXTRA_FLAGS) -o $(NAME)
	@echo "\033[1;35m---> PHILOSOPHERS SUCCESSFULLY COMPILED\033[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objs
	$(CC) -c $(CFLAGS) $(EXTRA_FLAGS) -I /usr/local/include $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	@echo "\033[1;38;5;208m---> All .o files were deleted\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;32m---> ./$(NAME) was deleted\033[0m"

valgrind:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes valgrind --tool=helgrind --log-file=valgrind-out.txt ./philo

re: fclean all

.PHONY: all clean fclean re force norminette
