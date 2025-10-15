# ========= Config =========
NAME      := fixed
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98 -I.
SRCDIR    := src
OBJDIR    := obj

SRC       := $(wildcard $(SRCDIR)/*.cpp)
OBJ       := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
DEPS      := $(OBJ:.o=.d)

# ========= Rules =========
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
