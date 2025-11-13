
NAME     := scavtrap
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP -I.

SRC_DIR  := src
OBJ_DIR  := obj

# List your sources here (add/remove as needed)
SRC      := $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/ClapTrap.cpp \
            $(SRC_DIR)/ScavTrap.cpp

OBJ      := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS     := $(OBJ:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Create obj/ subdirs mirroring src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)
