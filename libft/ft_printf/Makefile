# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 12:52:05 by jhallama          #+#    #+#              #
#    Updated: 2020/01/29 16:28:45 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = choose_type_di.c choose_type_f.c choose_type_o.c choose_type_u.c choose_type_x.c conversion_c.c conversion_cap_x.c conversion_di.c conversion_f.c conversion_o.c conversion_p.c conversion_percentage.c conversion_s.c conversion_u.c conversion_x.c format_specification_fields.c ft_printf.c

HEADERS = -I ft_printf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) $(HEADERS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
