# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 15:40:02 by htkachuk          #+#    #+#              #
#    Updated: 2018/04/02 15:40:04 by htkachuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/which_fract_bonus.c src/main.c src/bonus.c src/ft_key.c src/ft_create.c src/make_fract.c src/mouse_zoom.c src/which_fract.c

OBJ = $(SRC:.c=.o)

FLAG =  -O3 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C ./libft	
	@ gcc -o $(NAME) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit 

%.o: %.c src/fractol.h
	@ gcc -c $(FLAG) -o $@ $<

clean:
	@ /bin/rm -f $(OBJ)
	@ make -C ./libft clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C ./libft fclean

re: fclean all

.PHONY: re all clean fclean
