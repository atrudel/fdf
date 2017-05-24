# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:02:38 by atrudel           #+#    #+#              #
#    Updated: 2017/02/08 16:22:55 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_PATH = libft

SRC = 	main.c\
		parsing.c\
		line.c\
		grid.c\
		transformations.c\
		utils.c\
		commands1.c\
		commands2.c \
		projections.c \
		image.c \
		color.c \
		parameter_init.c

OBJ = $(SRC:.c=.o)

INC = 	fdf.h\
		$(LIB_PATH)/includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)/libft.a
	gcc -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit \
		-L $(LIB_PATH) -lft

$(LIB_PATH)/libft.a: $(LIB_PATH)/Makefile $(LIB_PATH)/includes/libft.h
	@make -C $(LIB_PATH)/ fclean && make -C $(LIB_PATH)
	@echo "libft created"

%.o: %.c $(INC)
	gcc -o $@ -c $< $(FLAGS) -I $(LIB_PATH)/includes

clean:
	make -C $(LIB_PATH)/ clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_PATH)/ fclean
	rm -f fdf

re: fclean all

norme:
	make -C $(LIB_PATH)/ norme
	norminette $(SRC) $(INC)
