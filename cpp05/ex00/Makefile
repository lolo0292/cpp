NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = sources
INC_DIR = include
OBJ_DIR = obj

SRC = main.cpp \
      $(SRC_DIR)/Bureaucrat.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INC_DIR)

all: $(NAME)

GREEN		= \033[0;32m

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✔ Compilation complete$(RESET)"


$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
