# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 14:49:06 by atrudel           #+#    #+#              #
#    Updated: 2016/12/13 22:39:06 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./src
OBJ_PATH = ./obj
INC_PATH = ./includes

INC_FILES = 	libft.h \
		get_next_line.h

SRC_FILES =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_atoi_hexa.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strdeljoin.c \
			ft_strtrim.c \
			ft_strappend_char.c \
			ft_strappend_char_before.c \
			ft_strchop_before.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_intmaxtoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstadd_end.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstsize.c \
			ft_lstprint_element.c \
			ft_lstprint.c \
			ft_lstpush_back_params.c \
			get_next_line.c

OBJ_FILES =	$(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))
INC = $(addprefix $(INC_PATH)/, $(INC_FILES))

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I $(INC_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -Rf $(OBJ_PATH)
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(INC)

.PHONY: all clean fclean re norme
