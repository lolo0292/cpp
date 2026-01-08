NAME	= animal_brain

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

INCDIR	= include
SRCDIR	= src
OBJDIR	= obj

SRCS	= main.cpp \
		  $(SRCDIR)/Animal.cpp \
		  $(SRCDIR)/Dog.cpp \
		  $(SRCDIR)/Cat.cpp \
		  $(SRCDIR)/Brain.cpp

OBJS	= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
