# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjung <tjung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 00:34:11 by tjung             #+#    #+#              #
#    Updated: 2022/03/31 15:03:16 by tjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		diamondtrap

CC = 		clang++

CFLAGS =	-std=c++98 -Wall -Wextra -Werror
WSHADOW =	-Wshadow
WNOSHADOW =	-Wno-sadow

SRCS =		main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp

OBJS =		$(SRCS:.cpp=.o)

.PHONY:		all clean fclean re wsh wno wshwno

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

wsh:		$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CC) $(CFLAGS) $(WSHADOW) -o $(NAME) $(OBJS)
			@echo "\033[0m"

wno:		$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CC) $(CFLAGS) $(WNOSHADOW) -o $(NAME) $(OBJS)
			@echo "\033[0m"

wshwno:		$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CC) $(CFLAGS) $(WSHADOW) $(WNOSHADOW) -o $(NAME) $(OBJS)
			@echo "\033[0m"
