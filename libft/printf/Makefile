# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 10:53:12 by hmiyake           #+#    #+#              #
#    Updated: 2019/09/03 14:42:58 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

SRCO = *.o

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Werror -Wextra -c $(SRCS)

clean:
	@rm -f $(SRCO)

re: clean all
