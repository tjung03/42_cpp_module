NAME =		static

CPP = 		c++

#CPPFLAGS =	-pedantic -W -Wall -Wextra -Werror
CPPFLAGS =	-pedantic -std=c++98 -W -Wall -Wextra -Werror
# stoi() stof() stod() 를 사용하기에 -std=c++98 플래그에서 컷 당함
# 그러므로 빼고 테스트를 진행하도록 함.

SRCS =		main.cpp \
			Converter.cpp \
			Exception.cpp

OBJS =		$(SRCS:.cpp=.o)

.PHONY:		all clean fclean re

%.o : %.cpp
			$(CPP) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
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
