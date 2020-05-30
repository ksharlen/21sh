/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:17:44 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 00:42:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <assert.h>
# include <errno.h>
# include <stdint.h>

# include "ft_printf.h"
# include "ft_getopt.h"
# include "ft_dbl_list_cycl.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define FD_MAX				7198
# define BUFF_SIZE			20

# define DECIMAL				10

# define FIRST_SYM				0

# define FLAG_ON			1
# define FLAG_OFF			0

/*
**rwfile
*/
# define ESUCH 				"no such file"
# define SPLIT_SYM			'\n'
# define R_FVAL				get_name_value
# define W_FVAL 			change_the_value_by_name_in_file
# define WEND_FVAL			ft_push_end_file
# define S_RWSUPER 			600

# define FT_COLOR_DFLT		"\e[0m"
# define FT_COLOR_BLUE		"\e[34;1m"
# define FT_COLOR_RED		"\e[31;1m"
# define FT_COLOR_CYAN		"\e[36;1m"
# define FT_COLOR_YELLOW	"\e[33;1m"
# define FT_COLOR_GREEN		"\e[32;1m"

/*
**SYS_ERRORS
*/
enum			e_errors
{
	RET_ERROR = -1,
	E_OPEN,
	E_CLOSE,
	E_READ,
	E_OPENDIR,
	E_CLOSEDIR,
	E_READDIR,
	E_FORK,
	E_WAIT,
	E_SIGNAL,
	E_TIME,
	E_CTIME,
	E_WAITPID,
	E_KILL,
	E_GETCWD3,
	E_MALLOC,
	E_CHDIR,
	E_STAT,
	E_FSTAT,
	E_LSTAT,
	E_GETPWUID,
	E_TCGETATTR,
	E_TCSETATTR,
	E_TGETENT,
	E_TGETSTR,
	E_TGOTO,
	E_TPUTS,
	E_WRITE
};

typedef int8_t	t_error;
typedef	uint8_t	t_byte;

# define BYTE t_byte

enum			e_type
{
	UCHAR,
	CHAR,
	USHORT,
	SHORT,
	UINT,
	INT,
	ULONG,
	LONG,
	STRING,
};

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

enum			e_rw
{
	FILE_ERROR = -1,
	RW_SUCCESS
};

enum			e_err
{
	FAILURE = -1,
	SUCCESS
};

enum			e_simp
{
	F = FAILURE,
	S = SUCCESS
};

/*
**STRINGS
*/
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, int n);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strcasecmp(const char *s1, const char *s2);
char			*ft_strsetalloc(const char sym, size_t size);
char			*ft_strmoveptr_end(const char *str, char sym);
char			**ft_strsplit_skip_space(char *str, char sym);
void			ft_strdel_split(char **del);
char			*ft_stroneof(const char *str, const char *find);
char			*ft_strscat(char *dst, char *src, const char sym);
char			*ft_strnjoin(const char *str1, const char *str2,
	size_t num_str1, size_t num_str2);
char			*ft_strnstr(const char *big,
	const char *little, size_t len);

/*
**MEMORY
*/
void			*ft_memset(void	*buf, int value, size_t num);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int ch, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memsub(const void *s, unsigned int start, size_t len);
void			*ft_memnjoin(const void *s1, const void *s2,
	size_t num1, size_t num2);
size_t			ft_memnlen(const void *s, int n, size_t size);
int				ft_memischar(const char *str, int n, size_t size);
int				ft_memisstr(const char *str,
	const char *chek_format, size_t size);

/*
**PRINT
*/
int				ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**OTHER
*/
int				ft_ischar(const char *str, int c);
int				ft_isstr(const char *str, const char *check_symbals);
int				ft_atoi(const char *nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
void			ft_swap(int *a, int *b);
size_t			ft_size_num(int a);
unsigned		ft_set_bit(unsigned val, unsigned num);
unsigned		ft_set_bits(unsigned val, unsigned bits, unsigned num);
unsigned		ft_bitscpy(unsigned value, unsigned inval, unsigned num);
size_t			ft_wcslen(const wchar_t *str);
void			ft_ustrdel(unsigned char **str);
const char		*ft_skipfirst(const char *str, int sym);
char			*ft_setncat(char *str, int sym, size_t size);
char			*ft_skipnv_sym(const char *str);
char			*ft_strskipinv_sym(const char *str, char sym);
char			*ft_skip_word_sym(const char *str, char sym);
char			*ft_skiptabs(const char *str);
char			*ft_skip_before(const char *str, char sym);
char			*ft_skiptabs_sym(const char *str, char sym);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isspace(int c);
ssize_t			ft_pow(int n, int level);
int				ft_revers(int n);
void			ft_lstadd_end(t_list **begin_list, t_list *elem);
int				get_next_line(const int fd, char **line, char signal);
void			ft_lstfreeone(void *content, size_t content_size);
t_list			*ft_lstelem(t_list *begin_list,
	size_t index, size_t lst_size);
size_t			ft_lstsize(t_list *beg);
ssize_t			ft_arrfind(int *arr, int data, size_t size);
t_list			*ft_lstreplace(t_list **rep, void *content,
	size_t content_size);

/*
**BERORE_TAB
*/
char			*ft_strtabchr(const char *str, const char sym);
size_t			ft_strtablen(const char *str);
char			*ft_strtabdup(const char *str);

/*
**FILE
*/
char			*read_file_all(const char *path_name);
char			*get_name_value(const char *path_name, const char *name);
int				change_the_value_by_name_in_file(const char *path_name,
	const char *name, const char *value);
int				ft_push_end_file(const char *path_name, const char *data);
int				ft_set_next_line(const char *path_name, const char *data);

/*
**line
*/
size_t			ft_lineslen(char *const lines[]);
size_t			ft_print_lines(char *const str[]);
char			**ft_linedup(char *const *line);

/*
**errors
*/
void			ft_err_str(t_error nerror, const char *add_text);
void			ft_err_exit(t_error nerror, const char *add_text);

/*
**NEW_FUN
*/
int				ft_atoi_base(const char *str, const int base);
int				ft_atoi_base_ptr(const char *str, const int base, char **ptr);
size_t			ft_num_words(const char *str, const char *entry_sym);
void			*ft_memdup(void *content, size_t len_content);
void			ft_print_arr(void *arr, size_t size, BYTE type);
const char		*ft_skip_space(const char *str);
void			ft_print_nsym(int fd, char sym, size_t n);
char			*ft_strreplace(char *in, char *from);
void			ft_swap_sym(char *one, char *two);
void			ft_chk_null_ptr(void *ptr, t_error nerror);
void			ft_chk_sys_error(ssize_t val, t_error nerror);
long long		ft_abs(long long num);
void			ft_num_mod(long long *num);
ssize_t			ft_write(int fildes, const void *buf, size_t nbyte);

#endif
