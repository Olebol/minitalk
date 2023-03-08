NAME := get_next_line.a
NICKNAME := GNL

# Directories
HDR_DIR := lib
SRC_DIR := src
OBJ_DIR := obj

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra

# Includes
HDR_FILES :=	get_next_line.h

# Files
SRC_FILES :=	get_next_line.c	\
				get_next_line_utils.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
HDR := $(addprefix $(HDR_DIR)/, $(HDR_FILES))

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(OBJ)
	@echo "$(YELLOW)$(BOLD)Compiling $(NICKNAME)...$(RESET)"
	@ar rc ${NAME} $<
	@echo "$(GREEN)$(BOLD)$(NICKNAME) Compiled$(RESET)"

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

norminette:
	@norminette $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all norminette clean fclean re
