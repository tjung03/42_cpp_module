# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjung <tjung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:43:36 by tjung             #+#    #+#              #
#    Updated: 2022/03/24 17:37:11 by tjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		zombie

CC = 		clang++

CFLAGS =	-Wall -Wextra -Werror

SRCS =		main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp

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
