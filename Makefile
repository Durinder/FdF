# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:10:31 by jhallama          #+#    #+#              #
#    Updated: 2020/01/29 16:30:33 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c 

HEADERS = -I fdf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/
	@make -C libft/ft_printf/
	@gcc -Wall -Wextra -Werror -c $(SRC) $(HEADERS)
	@ar -rc library.a $(OBJ)
	@ranlib library.a
	@gcc -Wall -Wextra -Werror library.a libft/libft.a libft/ft_printf/ft_printf.a $(SRC) $(HEADERS) -o $(NAME)
	@echo "Made evvvrything!"

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean
	@echo "Cleaned .o files"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f library.a
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean
	@echo "Cleaned .o files, .a files and fdf"

re: fclean all
