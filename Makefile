# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:50:01 by hmiyake           #+#    #+#              #
#    Updated: 2019/12/16 23:43:18 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CFILES := $(addprefix ./srcs/, main.c\
			print.c\
			cd.c \
			env.c \
			real_func.c)

OFILES := $(CFILES:.c=.o)

INCLUDES := -I includes
LIBFT := ./libft/
LDFLAGS := -L $(LIBFT) -lft

CFLAGS := -Wall -Werror -Wextra
# -Wshadow -pedantic -g -std=c11

F := -fsanitize=address

all: $(NAME) 

f:
	gcc $(CFILES) -g -L libft/ -I libft/ $(F) -lft

# C flgas?
$(NAME): $(OFILES)
	@make -C $(LIBFT)
	@$(CC) -o  $@ $^ $(CFLAGS) libft/libft.a $(LDFLAGS)

clean:
	@make -C libft/ clean
	@rm -f $(OFILES)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
