##
## EPITECH PROJECT, 2021
## 309pollution
## File description:
## Makefile
##

CC	=	g++

SRC	=	./src/main.cpp	\
		./src/309pollution.cpp

CXXFLAGS	=	-Iinclude -g3 -Wall -Wextra

OBJ	=	$(SRC:.cpp=.o)

NAME	=	309pollution

pollution:	$(NAME)

all: pollution

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean_pollution:
	rm -rf $(OBJ)

clean:	clean_pollution

fclean_pollution:	clean_pollution
	rm -rf $(NAME)

fclean: fclean_pollution

re_pollution:	fclean_pollution pollution

re: re_pollution