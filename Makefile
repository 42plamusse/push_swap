# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/04/24 20:13:03 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ./libft

# src / obj files

SRC			= checker.c \
			  instructions.c \
			  create_stack.c \
			  push.c \
			  swap.c \
			  rotate.c \
			  rev_rotate.c \
			  lstdel.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: checker

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)/checker.h
	$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR)

checker: $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ) $(LIB_LNK)

clean:
	@$(MAKE) fclean -C $(L_FT)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
