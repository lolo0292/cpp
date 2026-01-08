NAME = forms

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = sources
INC_DIR = include
OBJ_DIR = obj

SRC = main.cpp \
      $(SRC_DIR)/Bureaucrat.cpp \
      $(SRC_DIR)/AForm.cpp \
      $(SRC_DIR)/ShrubberyCreationForm.cpp \
      $(SRC_DIR)/RobotomyRequestForm.cpp \
      $(SRC_DIR)/PresidentialPardonForm.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
