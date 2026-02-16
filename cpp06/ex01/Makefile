NAME        := serialize

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

INCDIR      := includes
SRCDIR      := srcs
OBJDIR      := obj

SRCS        := main.cpp \
               $(SRCDIR)/Serializer.cpp \
               $(SRCDIR)/Data.cpp

OBJS        := $(SRCS:%.cpp=$(OBJDIR)/%.o)

RM          := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
