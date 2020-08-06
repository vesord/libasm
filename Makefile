#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/08/04 12:23:55 by matrus            #+#    #+#             *#
#*   Updated: 2020/08/04 12:23:55 by matrus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libasm.a

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.s)
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

SRC_B_DIR = src_bonus
SRC_B = $(wildcard $(SRC_B_DIR)/*.s)
OBJ_DIR = obj
OBJ_B = $(SRC_B:$(SRC_B_DIR)/%.s=$(OBJ_DIR)/%.o)

CC = clang
FLAGS = -Wall -Wextra -Werror
NASM_COMPILE = nasm -felf64

.PHONY: all
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $^ 

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	$(NASM_COMPILE) $< -o $@

.PHONY: bonus
bonus: $(OBJ_DIR) $(OBJ_B) $(NAME)
	ar -r $(NAME) $(OBJ_B) 

$(OBJ_B): $(OBJ_DIR)/%.o: $(SRC_B_DIR)/%.s
	$(NASM_COMPILE) $< -o $@

$(OBJ_DIR):
	mkdir $@

.PHONY: test
test: all
	$(CC) $(FLAGS) -I. main.c -L. -lasm -o $@
	./$@

.PHONY: test_bonus
test_bonus: bonus
	$(CC) $(FLAGS) -I. main_bonus.c -L. -lasm -o $@
	./$@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)


.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf test*

.PHONY: re
re: fclean all
