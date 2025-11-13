
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98 -I.
DEPFLAGS  := -MMD -MP

SRC_DIR   := src
OBJ_DIR   := obj

NAME      := fragtrap

SRCS      := \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/ClapTrap.cpp \
	$(SRC_DIR)/ScavTrap.cpp \
	$(SRC_DIR)/FragTrap.cpp

OBJS      := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS      := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
