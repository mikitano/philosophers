# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 14:26:02 by mkitano           #+#    #+#              #
#    Updated: 2025/12/07 17:47:58 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
EXEC = $(BIN_DIR)/$(NAME)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

SRC_FILES = main.c \
		utils.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, philo.h)

CC = cc
AR = ar

ARFLAGS = crs
CCFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I $(INCLUDE_DIR)

RM = rm
RMFLAGS = -rf

all: $(EXEC)

$(EXEC) : $(OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(OBJS) -o $(EXEC)
		@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED in $(BIN_DIR)/!"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CCFLAGS) $(IFLAGS) -c $< -o $@
		@echo "[\033[0;32mOK\033[0m] COMPILED $<"

clean :
		@$(RM) $(RMFLAGS) $(OBJ_DIR)
		@echo "[\033[0;32mOK\033[0m] CLEAR files!"

fclean : clean
		@$(RM) $(RMFLAGS) $(BIN_DIR)
		@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re : fclean all
		$(info Project REBUILD!)

.PHONY: all clean fclean re