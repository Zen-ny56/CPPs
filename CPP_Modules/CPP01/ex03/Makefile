# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naadam <naadam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 19:44:04 by naadam            #+#    #+#              #
#    Updated: 2024/06/24 18:04:25 by naadam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= violence
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJDIR = obj
SRC 	  = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ_FILES = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re