# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 18:29:23 by ksharlen          #+#    #+#              #
#    Updated: 2020/02/06 20:48:46 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_LIB				:=	lib/
DIR_LIBFT			:=	$(DIR_LIB)libft/

#DIR_SRCS
DIR_SRC				:=	./src/
DIR_SRC_INPUT		:=	$(DIR_SRC)input/
DIR_SRC_TERMCAP		:=	$(DIR_SRC_INPUT)termcap/
DIR_SRC_INPUT_SCREEN	:=	$(DIR_SRC_INPUT)screen/
DIR_SRC_INPUT_ADD_MODES	:=	$(DIR_SRC_INPUT)/additional_modes/
DIR_SRC_INIT		:=	$(DIR_SRC)init/
DIR_UTILS			:=	$(DIR_SRC)internal_utilities/
DIR_UTILS_ENV		:=	$(DIR_UTILS)21sh_env

DIRS_SRC			:=	$(DIR_SRC)\
							$(DIR_SRC_INPUT)\
							$(DIR_SRC_TERMCAP)\
							$(DIR_SRC_INPUT_ADD_MODES)\
							$(DIR_SRC_INIT)\
							$(DIR_UTILS)\
							$(DIR_UTILS_ENV)\
							$(DIR_SRC_INPUT_SCREEN)

#DIR_OBJS
DIR_OBJ				:=	./bin/

#DIR_INCLUDE
DIR_INCLUDE_NAME	:=	./include/
DIR_INCLUDE_LIBFT	:=	$(DIR_LIBFT)include/
DIR_INCLUDE_INPUT	:=	$(DIR_INCLUDE_NAME)input

DIR_INCLUDES		:=	$(DIR_INCLUDE_LIBFT)\
							$(DIR_INCLUDE_NAME)\
							$(DIR_INCLUDE_INPUT)

#DIRS_END

#SRCS
SRCS				:=	main.c\
							input_getch.c\
							input_mode_term.c\
							input_init.c\
							input_cursor_pos.c\
							input_termcap.c\
							input_common.c\
							input_error.c\
							input_greeting.c\
							input_process_key_press.c\
							input_refresh_screen.c\
							input_move_cursor.c\
							input_common_screen.c\
							input_key_tools.c\
							input_parse_page_keys.c\
							input_parse_keys_shift_words.c\
							input_copy_paste_cut.c\
							input_ctr_keys.c\
							input_additional_modes.c\
							input_quote.c\
							input_quote_greet.c\
							input_search_key_char.c\
							21sh_cd_home_dir.c\
							21sh_cd.c\
							21sh_echo.c\
							21sh_getenv.c\
							21sh_pwd.c\
							21sh_setenv.c\
							21sh_unsetenv.c\
							21sh_init_env.c\
							21sh_init.c\
							21sh_init_structs.c\
							input.c

#OBJS
OBJS				:=	$(SRCS:.c=.o)

#HEADERS
HEADERS				:=	libft.h\
							input_init.h\
							input_macros.h\
							input_parse_key.h\
							input_error.h\
							input_termcap.h\
							input_greeting.h\
							21sh_init.h\
							21sh_limits.h\
							21sh_struct.h

#LIBS
LIBFT				:=	libft.a

#COMPILE
СС					:=	gcc
CFLAGS				:=	-Wextra -Werror -Wall
CREATE_OBJ			:=	-c
PATH_OBJ			:=	$(addprefix $(DIR_OBJ), $(OBJS))
PATH_INCLUDES		:=	$(addprefix -I ,$(DIR_INCLUDES))
PATH_LIBFT			:=	$(DIR_LIBFT)$(LIBFT)

#OPERATIONS
CREATE_FOLDER		:=	mkdir -p
MAKE_LIBFT			:=	make -C $(DIR_LIBFT)
REMOVE				:=	rm -rf

NAME	:=	test

vpath %.c $(DIRS_SRC)
vpath %.o $(DIR_OBJ)
vpath %.h $(DIR_INCLUDES)
vpath %.a $(DIR_LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PATH_OBJ) $(PATH_LIBFT) -o $@ -ltermcap

$(OBJS):%.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) $(CFLAGS) $(CREATE_OBJ) $< -o $(DIR_OBJ)$@ $(PATH_INCLUDES)

$(DIR_OBJ):
	$(CREATE_FOLDER) $@

$(LIBFT):
	$(MAKE_LIBFT)

clean:
	$(REMOVE) $(OBJS)
	$(REMOVE) $(DIR_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

echo:
	echo $(DIR_INCLUDES)

.PHONY: test
.SILENT: all $(NAME) $(OBJS) $(DIR_OBJ) $(LIBFT) clean fclean re $(OBJS_TEST) $(TEST) test
