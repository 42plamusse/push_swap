# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/04/27 20:53:15 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# programs
CHECKER		= checker
PUSHSWAP	= push_swap

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ./libft

# src / obj files

SRC			= create_stack.c \
			  utils.c \
			  instructions.c \
			  push.c \
			  swap.c \
			  rotate.c \
			  rev_rotate.c \
			  commit_instruction.c
				

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_CHECKER	= $(OBJ_DIR)/checker.o
OBJ_PUSHSWAP= $(OBJ_DIR)/push_swap.o

# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: push_swap checker

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR)

$(OBJ_CHECKER): $(SRC_DIR)/checker.c $(INC_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR)

$(OBJ_PUSHSWAP): $(SRC_DIR)/push_swap.c $(INC_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR)

push_swap: $(OBJ_DIR) $(OBJ) $(OBJ_PUSHSWAP)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ) $(OBJ_PUSHSWAP) $(LIB_LNK)

checker: $(OBJ_DIR) $(OBJ) $(OBJ_CHECKER)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ) $(OBJ_CHECKER) $(LIB_LNK)

clean:
	@$(MAKE) fclean -C $(L_FT)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(CHECKER) $(PUSHSWAP)

re:
	@$(MAKE) fclean
	@$(MAKE) all
