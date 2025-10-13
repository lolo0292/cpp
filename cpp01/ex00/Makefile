NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
SRC_DIR = src
OBJ_DIR = objs
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Zombie.cpp \
       $(SRC_DIR)/newZombie.cpp \
       $(SRC_DIR)/randomChump.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
