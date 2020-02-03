NAME		:=	libinternal_utils.a

DIR_BIN		:=	./bin/
DIR_SRC		:=	./
DIR_SRC_ENV	:=	./ftsh_env
DIRS_SRC	:=	$(DIR_SRC) $(DIR_SRC_ENV)
DIR_INCLUDE	:=	../include/ ./

DIR_LIBFT	:=	../../lib/libft/
DIR_INCLUDE_LIBFT	:=	$(DIR_LIBFT)include/

SRCS		:=	ftsh_cd_home_dir.c\
					ftsh_cd.c\
					ftsh_echo.c\
					ftsh_getenv.c\
					ftsh_pwd.c\
					ftsh_setenv.c\
					ftsh_unsetenv.c

OBJS		:=	$(SRCS:.c=.o)

OBJS_BIN	:=	$(addprefix $(DIR_BIN), $(OBJS))

HEADERS		:=	internal_utilities.h

CC			:=	gcc
CFLAGS		:=	-Wextra -Werror -Wall

vpath	%.c $(DIRS_SRC)
vpath	%.o $(DIR_BIN)
vpath	%.h $(DIR_INCLUDE) $(DIR_INCLUDE_LIBFT)
vpath	%.a $(DIR_LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS_BIN)

$(OBJS):%.o:%.c $(HEADERS) | $(DIR_BIN)
	$(CC) $(CFLAGS) -c $< -o $(DIR_BIN)$@ $(addprefix -I , $(DIR_INCLUDE) $(DIR_INCLUDE_LIBFT))

$(DIR_BIN):
	mkdir -p $@

echo:
	@echo $(addprefix -I, $(DIR_INCLUDE) $(DIR_INCLUDE_LIBFT))
