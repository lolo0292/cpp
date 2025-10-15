NAME      := fixed
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98 -I.
DEPFLAGS  := -MMD -MP

SRC_DIR   := src
OBJ_DIR   := obj

SRCS      := $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp
OBJS      := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS      := $(OBJS:.o=.d)

all: $(NAME)
$(NAME): $(OBJS) ; $(CXX) $(CXXFLAGS) $(OBJS) -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Fixed.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@
$(OBJ_DIR): ; mkdir -p $(OBJ_DIR)
clean: ; $(RM) -r $(OBJ_DIR)
fclean: clean ; $(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include $(DEPS)
