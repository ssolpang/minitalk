# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 19:53:05 by jkwak             #+#    #+#              #
#    Updated: 2022/05/06 20:34:56 by jkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = server.o
CLIENT_OBJ = client.o

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(LIBFT) :
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)/$(LIBFT) .

$(SERVER) :	$(SERVER_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) :	$(CLIENT_OBJ) $(LIBFT)	
		$(CC) $(CFLAGS) -o $@ $^

clean :
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		make clean -C $(LIBFT_DIR)

fclean : clean
		$(RM) $(SERVER) $(CLIENT) $(LIBFT)
		make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all clean fclean re
