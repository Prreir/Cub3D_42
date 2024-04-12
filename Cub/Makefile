# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 20:23:41 by lugoncal          #+#    #+#              #
#    Updated: 2024/04/12 22:11:19 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_YELLOW		=	\033[0;93m
_BLUE		=	\033[0;34m
_CYAN		=	\033[0;36m
_GREEN		=	\033[0;32m
_PURPLE		=	\033[0;35m
_RED		=	\033[0;31m
_WHITE		=	\033[0;37m

NAME	:=	cub3D
CC	:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g
MINILIB	:=	-L ./MiniLibX -lmlx -Ilmlx -lXext -lX11 -lm

INCLUDE	=	-I ./Include/\
			-I ./Libft/\
			-I ./MiniLibX

LIB_PATH	=	./Libft/
LIB_NAME	=	libft.a
LIB	=	$(LIB_PATH)$(LIB_NAME)

MINI_PATH	=	./MiniLibX/
MINI_NAME	=	libmlx.a
MINI	=	$(MINI_PATH)$(MINI_NAME)

SRC_DIR	:=	./Src/
OBJ_DIR	:=	./Obj/

SRC	:=	main.c \
		check.c \
		boom.c \
		info.c \
		utils.c \
		len.c \
		textures.c \
		


SOURCES	:=	$(addprefix $(SRC_DIR), $(SRC))
OBJS	:=	$(SRC:.c=.o)
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJS))

all:	$(LIB) $(NAME)

$(LIB):
	@echo "$(_CYAN)      ██████╗██╗   ██╗██████╗ ██████╗ ██████╗     ";
	@echo "$(_CYAN)     ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗    ";
	@echo "$(_CYAN)     ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║    ";
	@echo "$(_CYAN)     ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║    ";
	@echo "$(_CYAN)     ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝    ";
	@echo "$(_CYAN)      ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝     ";
	@echo "$(_CYAN) ====  Project made by: lugoncal && mmassa-r  ====";
	@echo "$(_YELLOW)  Making LIBFT...";
	@make -sC $(LIB_PATH)
	@echo "$(_YELLOW)  LIBFT Created.";
	@echo "$(_YELLOW)  Making MiniLibX...";
	@make -sC $(MINI_PATH)
	@echo "$(_YELLOW)  MiniLibX Created.";

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB) $(MINILIB) $(INCLUDE)
	@echo "$(_YELLOW)  All files compiled into '$(OBJ_DIR)'.";
	@echo "$(_YELLOW)  Executable '$(NAME)' created.";

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -sC $(LIB_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(_RED)  '"$(OBJ_DIR)"' has been deleted.";

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "$(_RED)  '"$(NAME)"' has been deleted.";

re: fclean all

.PHONY: all clean fclean re