# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abchan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 13:09:32 by abchan            #+#    #+#              #
#    Updated: 2018/04/03 23:09:50 by shomami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c \
		parsefillit.c\
		read.c\
		solve.c\
		map.c

OBJ = $(FILES:.c=.o)

LIBFT = libft -lft

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(CFLAGS) -c $(FILES)
	gcc	$(OBJ) -L $(LIBFT) -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
