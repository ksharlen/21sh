# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 21:51:15 by ksharlen          #+#    #+#              #
#    Updated: 2020/02/23 15:24:46 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						:=	test

#!SRCS
SRC_MAIN					:=	main.c

SRC_INIT					:=	init.c\
									init_env.c\
									init_structs.c

SRC_INPUT					:=	input.c\
									input_getch.c\
									input_mode_term.c\
									input_init.c\
									input_cursor_pos.c\
									input_termcap.c\
									input_common.c\
									input_error.c\
									input_greeting.c\
									input_greet_init.c\
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
									input_search_key_char.c\
									input_change_win.c\
									input_ctr_t.c\
									input_set_of_instr_for_getch.c\
									input_history.c\
									input_bonus_instr.c\
									input_wrapper_func.c

SRC_IU						:=	iu_cd_home_dir.c\
									iu_cd.c\
									iu_echo.c\
									iu_getenv.c\
									iu_pwd.c\
									iu_setenv.c\
									iu_unsetenv.c\
									iu_init_var_env.c

SRC_HIST					:=	history_init.c\
									history_fill_flist.c\
									history_find_history.c\
									history_move.c\
									history_del.c

SRC_PARSER					:=	parser.c\
									parser_list.c\
									parser_find_delimiter.c\
									parser_common.c\
									parser_args.c\
									parser_quotes.c

SRCS						:=	$(SRC_MAIN)\
									$(SRC_INIT)\
									$(SRC_INPUT)\
									$(SRC_IU)\
									$(SRC_HIST)\
									$(SRC_PARSER)

OBJS						:=	$(SRCS:.c=.o)

DIR_SRC						:=	./src/
DIR_INIT					:=	$(DIR_SRC)init/
DIR_INPUT					:=	$(DIR_SRC)input/

DIRS_INPUT					:=	$(DIR_INPUT)\
									$(DIR_INPUT)additional_modes/\
									$(DIR_INPUT)bonus/\
									$(DIR_INPUT)greeting/\
									$(DIR_INPUT)screen/\
									$(DIR_INPUT)termcap/\

DIR_IU						:=	$(DIR_SRC)internal_utilities/
#env_dirs
DIR_HIST					:=	$(DIR_SRC)history/
DIR_PARSER					:=	$(DIR_SRC)parser/

DIRS_SRC					:=	$(DIR_SRC)\
									$(DIR_INIT)\
									$(DIRS_INPUT)\
									$(DIR_IU)\
									$(DIR_HIST)\
									$(DIR_PARSER)

#!HEADERS
MAIN_HEADERS				:=	sh.h\
									history.h\
									internal_utilities.h\
									sh_bonus.h\
									sh_init.h\
									sh_limits.h\
									sh_struct.h

INPUT_HEADERS				:=	input_error.h\
									input_greeting.h\
									input_init.h\
									input_macros.h\
									input_parse_key.h\
									input_termcap.h

PARSER_HEADERS				:=	parser.h

HEADERS						:=	$(MAIN_HEADERS)\
									$(INPUT_HEADERS)\
									$(PARSER_HEADERS)

DIR_INCLUDE					:=	./include/
DIR_INCLUDE_INPUT			:=	$(DIR_INCLUDE)input/
DIR_INCLUDE_PARSER			:=	$(DIR_INCLUDE)parser/

DIRS_INCLUDE				:=	$(DIR_INCLUDE)\
									$(DIR_INCLUDE_INPUT)\
									$(DIR_INCLUDE_PARSER)

#!LIBFT
LIBFT						:=	libft.a
DIR_LIBFT					:=	./lib/libft/
DIR_LIBFT_INCLUDE			:=	$(DIR_LIBFT)include/

#!OTHER
CFLAGS						:=	-Wall -Wextra -Werror
DIR_OBJ						:=	./obj/
OBJS_WITH_PATH				:=	$(addprefix $(DIR_OBJ), $(OBJS))
PATH_HEADERS				:=	$(addprefix -I , $(DIRS_INCLUDE) $(DIR_LIBFT_INCLUDE))
PATH_LIBFT					:=	$(addprefix $(DIR_LIBFT), $(LIBFT))

#!ACTION
REMOVE						:=	rm -rf
MAKE_LIBFT					:=	make -C $(DIR_LIBFT)
MAKE_CLEAN_LIBFT			:=	make -C $(DIR_LIBFT) clean
MAKE_FCLEAN_LIBFT			:=	make -C $(DIR_LIBFT) fclean
CC							:=	gcc

vpath	%.c	$(DIRS_SRC)
vpath	%.o	$(DIR_OBJ)
vpath	%.h	$(DIRS_INCLUDE)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_WITH_PATH) $(PATH_LIBFT) -o $@ -ltermcap

$(OBJS):%.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $(DIR_OBJ)$@ $(PATH_HEADERS)

$(LIBFT):
	$(MAKE_LIBFT)

$(DIR_OBJ):
	mkdir -p $@

clean:
	$(REMOVE) $(OBJS_WITH_PATH)
	$(REMOVE) $(DIR_OBJ)
	$(MAKE_CLEAN_LIBFT)

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_FCLEAN_LIBFT)

re: fclean all

echo:
	echo $(DIRS_INCLUDE)

.SILENT: all $(NAME) $(OBJS) $(LIBFT) $(DIR_OBJ) clean fclean re