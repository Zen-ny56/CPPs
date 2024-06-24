# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naadam <naadam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 18:50:41 by naadam            #+#    #+#              #
#    Updated: 2024/06/23 18:51:19 by naadam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombiehorde
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJDIR = obj
SRC 	  = main.cpp Zombie.cpp

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