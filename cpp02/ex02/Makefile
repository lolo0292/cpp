NAME    := fixed
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -I.
DEPFLAGS:= -MMD -MP

SRC_DIR := src
OBJ_DIR := obj

SRCS    := $(SRC_DIR)/Fixed.cpp \
           $(SRC_DIR)/main.cpp
OBJS    := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)
