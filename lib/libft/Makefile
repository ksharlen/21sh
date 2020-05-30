# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 14:32:05 by ksharlen          #+#    #+#              #
#    Updated: 2020/02/25 00:42:58 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./ft_printf/Makefile
include ./dbl_list_cycl/Makefile
include ./queue/Makefile
include ./stack/Makefile
include ./gapbuf/Makefile

NAME 			:= libft.a
FLAGS 			:= -Wextra -Werror -Wall
CC 				:= gcc
REMOVE 			:= /bin/rm -rf
DIR_INCLUDE 	:= ./include

H_LIBFT			:= libft.h\
						ft_dbl_list_cycl.h\
						ft_queue.h\
						ft_stack.h\
						gap_buf.h

H_FT_PRINTF		:= ft_printf.h
HEADERS			:= $(H_LIBFT) $(H_FT_PRINTF)
DIR_BIN 		:= bin/
DIR_LIBFT		:= .
DIR_FT_PRINTF	:= ft_printf/
DIR_DLC			:= dbl_list_cycl/
DIR_QU			:= queue/
DIR_STK			:= stack/
DIR_GAPBUF		:= gapbuf/

SRC_LIBFT 		:= ft_arrfind.c\
						ft_atoi.c\
						ft_bzero.c\
						ft_isalnum.c\
						ft_isalpha.c\
						ft_isascii.c\
						ft_ischar.c\
						ft_isdigit.c\
						ft_isprint.c\
						ft_isspace.c\
						ft_isstr.c\
						ft_itoa.c\
						ft_lstadd.c\
						ft_lstadd_end.c\
						ft_lstdel.c\
						ft_lstdelone.c\
						ft_lstelem.c\
						ft_lstfreeone.c\
						ft_lstiter.c\
						ft_lstmap.c\
						ft_lstnew.c\
						ft_lstreplace.c\
						ft_lstsize.c\
						ft_memalloc.c\
						ft_memccpy.c\
						ft_memchr.c\
						ft_memcmp.c\
						ft_memcpy.c\
						ft_memdel.c\
						ft_memischar.c\
						ft_memisstr.c\
						ft_memmove.c\
						ft_memnjoin.c\
						ft_memnlen.c\
						ft_memset.c\
						ft_memsub.c\
						ft_pow.c\
						ft_putchar.c\
						ft_putchar_fd.c\
						ft_putendl.c\
						ft_putendl_fd.c\
						ft_putnbr.c\
						ft_putnbr_fd.c\
						ft_putstr.c\
						ft_putstr_fd.c\
						ft_revers.c\
						ft_size_num.c\
						ft_strcat.c\
						ft_strchr.c\
						ft_strclr.c\
						ft_strcmp.c\
						ft_strcpy.c\
						ft_strdel.c\
						ft_strdup.c\
						ft_strequ.c\
						ft_striter.c\
						ft_striteri.c\
						ft_strjoin.c\
						ft_strlcat.c\
						ft_strlen.c\
						ft_strmap.c\
						ft_strmapi.c\
						ft_strncat.c\
						ft_strncmp.c\
						ft_strncpy.c\
						ft_strnequ.c\
						ft_strnew.c\
						ft_strnjoin.c\
						ft_strnlen.c\
						ft_strnstr.c\
						ft_strrchr.c\
						ft_strsplit.c\
						ft_strstr.c\
						ft_strsub.c\
						ft_strtrim.c\
						ft_swap.c\
						ft_tolower.c\
						ft_toupper.c\
						get_next_line.c\
						ft_set_bit.c\
						ft_set_bits.c\
						ft_bitscpy.c\
						ft_wcslen.c\
						ft_ustrdel.c\
						ft_skipfirst.c\
						ft_getopt.c\
						ft_strcasecmp.c\
						ft_setncat.c\
						ft_strsetalloc.c\
						ft_skipinv_sym.c\
						ft_strskipinv_sym.c\
						ft_skip_word_sym.c\
						ft_skiptabs.c\
						ft_skip_before.c\
						ft_skiptabs_sym.c\
						ft_strmoveptr_end.c\
						ft_strsplit_skip_space.c\
						ft_print_lines.c\
						ft_lineslen.c\
						ft_strdel_split.c\
						ft_stroneof.c\
						ft_read_file.c\
						ft_push_to_file_name_val.c\
						ft_get_name_val_in_file.c\
						ft_push_end_file.c\
						ft_set_next_line.c\
						ft_strscat.c\
						ft_linedup.c\
						ft_strtabchr.c\
						ft_strtablen.c\
						ft_strtabdup.c\
						ft_errors.c\
						ft_atoi_base.c\
						ft_num_words.c\
						ft_atoi_base_ptr.c\
						ft_memdup.c\
						ft_print_arr.c\
						ft_skip_space.c\
						ft_strreplace.c\
						ft_swap_sym.c\
						ft_abs.c\
						ft_num_mod.c\
						ft_print_nsym.c\
						ft_write.c

SRCS 			:= $(SRC_LIBFT)\
						$(SRCS_FT_PRINTF)\
						$(SRC_DLC)\
						$(SRC_QU)\
						$(SRC_STK)\
						$(SRC_GAPBUF)

DIRS_FT_PRINTF	:= $(addprefix $(DIR_FT_PRINTF), $(DIRS_FT_PRINTF))

DIRS_SRC		:= $(DIRS_FT_PRINTF)\
						$(DIR_LIBFT)\
						$(DIR_DLC)\
						$(DIR_QU)\
						$(DIR_STK)\
						$(DIR_GAPBUF)

OBJS			:= $(SRCS:.c=.o)
OBJS_BIN		:= $(addprefix $(DIR_BIN), $(OBJS))

vpath %.c $(DIRS_SRC)
vpath %.h $(DIR_INCLUDE)
vpath %.o $(DIR_BIN)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcus $@ $(OBJS_BIN)

$(OBJS):%.o: %.c $(HEADERS) | $(DIR_BIN)
	$(CC) $(FLAGS) -c $< -o $(DIR_BIN)$@ $(addprefix -I, $(DIR_INCLUDE)) -pipe

$(DIR_BIN):
	mkdir -p $@

clean:
	$(REMOVE) $(OBJS)
	$(REMOVE) $(DIR_BIN)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY:	clean fclean re
.SILENT: all $(NAME) $(OBJS) $(DIR_BIN) clean fclean re
