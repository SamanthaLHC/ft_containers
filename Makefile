# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:01:55 by sle-huec          #+#    #+#              #
#    Updated: 2023/02/16 15:26:19 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT = ft_containers
NAME_STD = std_containers

# **************************************************************************** #
#    Compiler                                                                  #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98
FT_FLAG = -D FT
INCLUDE = -I./containers -I./iterators -I./utils -MMD

# **************************************************************************** #
#    Sources                                                                   #
# **************************************************************************** #


SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), \
		test_stack.cpp			\
		test_vector.cpp			\
		main.cpp				\
		subject_main.cpp)

OBJS_FT	= $(SRCS:$(SRCS_PATH)%.cpp=objs/ft_%.o)
DEPS_FT	= $(SRCS:$(SRCS_PATH)%.cpp=objs/ft_%.d)

OBJS_STD = $(SRCS:$(SRCS_PATH)%.cpp=objs/std_%.o)
DEPS_STD = $(SRCS:$(SRCS_PATH)%.cpp=objs/std_%.d)

# **************************************************************************** #
#    Rules                                                                     #
# **************************************************************************** #

all: $(NAME_FT) $(NAME_STD)

${NAME_FT}: ${OBJS_FT}
	${CXX} ${CXXFLAGS} ${OBJS_FT} -o ${NAME_FT}

${NAME_STD}: ${OBJS_STD}
	${CXX} ${CXXFLAGS} ${OBJS_STD} -o ${NAME_STD}

objs/ft_%.o: $(SRCS_PATH)%.cpp
	mkdir -p objs
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(FT_FLAG) -c $< -o $@

objs/std_%.o: $(SRCS_PATH)%.cpp
	mkdir -p objs
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf objs
	rm test1
	rm test2

fclean: clean
	rm -rf ${NAME_FT}
	rm -rf ${NAME_STD}

re: fclean
	
	make all

grind: ${NAME}
		valgrind ./$(NAME)

run: $(NAME)
	./$(NAME)

# **************************************************************************** #
#    Other                                                                     #
# **************************************************************************** #

.PHONY: clean fclean re grind run

-include ${DEPS_FT}
-include ${DEPS_STD}