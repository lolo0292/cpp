NAME		= bureaucrat

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -Iinclude

SRCS_DIR	= sources
OBJ_DIR		= obj

SRCS		= main.cpp \
			  $(SRCS_DIR)/Bureaucrat.cpp \
			  $(SRCS_DIR)/AForm.cpp \
			  $(SRCS_DIR)/ShrubberyCreationForm.cpp \
			  $(SRCS_DIR)/RobotomyRequestForm.cpp \
			  $(SRCS_DIR)/PresidentialPardonForm.cpp \
			  $(SRCS_DIR)/Intern.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Colors
GREEN		= \033[0;32m
BLUE		= \033[0;34m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Compilation complete$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Obj files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
