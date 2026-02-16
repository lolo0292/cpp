NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = srcs/main.cpp \
       srcs/Span.cpp

OBJS = $(SRCS:srcs/%.cpp=obj/%.o)

INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

obj/%.o: srcs/%.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
