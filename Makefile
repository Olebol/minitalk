SERVER := server
SERVER_NICKNAME := SERVER

CLIENT := client
CLIENT_NICKNAME := CLIENT

# Directories
HDR_DIR := lib
SRC_DIR := src
OBJ_DIR := obj

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra

# Includes
HDR_FILES :=	minitalk.h

# Files
SRC_FILES :=	client.c		\
				server.c		\
				utils.c			\
				client_utils.c	\

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
all: $(SERVER) ${CLIENT} 

$(SERVER): $(OBJ)
	@echo "$(YELLOW)$(BOLD)Compiling $(SERVER_NICKNAME)...$(RESET)"
	@gcc obj/server.o obj/utils.o -o $(SERVER)
	@echo "$(GREEN)$(BOLD)$(SERVER_NICKNAME) Compiled$(RESET)"

$(CLIENT): $(OBJ)
	@echo "$(YELLOW)$(BOLD)Compiling $(CLIENT_NICKNAME)...$(RESET)"
	@gcc obj/client.o obj/utils.o obj/client_utils.o -o $(CLIENT)
	@echo "$(GREEN)$(BOLD)$(CLIENT_NICKNAME) Compiled$(RESET)"

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

norminette:
	@norminette $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf ${SERVER}
	@rm -rf $(CLIENT)

re: fclean all

.PHONY: all norminette clean fclean re
