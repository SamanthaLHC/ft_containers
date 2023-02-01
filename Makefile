NAME = ft_containers

# **************************************************************************** #
#    Compiler                                                                  #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -MMD -g3 -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#    Sources  & includes                                                       #
# **************************************************************************** #

INCLUDE = -I containers

SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), \
		main.cpp)

OBJ_PATH = ./objs/
OBJS	= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJ_PATH)%.o)
DEPS	= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJ_PATH)%.d)


# **************************************************************************** #
#    Rules                                                                     #
# **************************************************************************** #

all: $(NAME)

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

$(OBJ_PATH)%.o: $(SRCS_PATH)%.cpp
	mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${OBJ_PATH}

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

-include ${DEPS}