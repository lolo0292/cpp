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


GREEN		= \033[0;32m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Compilation complete$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
