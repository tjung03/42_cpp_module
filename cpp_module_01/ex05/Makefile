# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjung <tjung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 02:35:41 by tjung             #+#    #+#              #
#    Updated: 2022/03/25 03:56:33 by tjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		harl

CC = 		clang++

CFLAGS =	-Wall -Wextra -Werror

SRCS =		main.cpp \
			Harl.cpp

OBJS =		$(SRCS:.cpp=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "\033[0m"

clean:
			@echo "\n\033[0;31mCleaning..."
			rm -rf $(OBJS)
			@echo "\033[0m"

fclean:		clean
			@echo "\033[0;31mRemoving executable..."
			rm -f $(NAME)
			@echo "\033[0m"

re: 		fclean all
