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

.PHONY: all
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $^ 

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	nasm -felf64 $< -o $@

.PHONY: bonus
bonus: $(OBJ_DIR) $(OBJ_B) $(NAME)
	ar -r $(NAME) $(OBJ_B) 

$(OBJ_B): $(OBJ_DIR)/%.o: $(SRC_B_DIR)/%.s
	nasm -felf64 $< -o $@

$(OBJ_DIR):
	mkdir $@

.PHONY: test
test:
	clang -I. main.c -L. -lasm -o $@
	./$@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)


.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf test

.PHONY: re
re: fclean all
