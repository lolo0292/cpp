

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
NAME     := brain
SRC      := main.cpp
OBJDIR   := obj
OBJ      := $(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS     := $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean re run
