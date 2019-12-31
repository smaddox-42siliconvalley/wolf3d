/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:26:28 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/21 16:32:56 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>

# define BASE_DIGITS "0123456789abcdef"
# define T_NODE(type, var, member) ((( type )(( var ) -> content )) ->  member )

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;
int						ft_atoi(const char *nptr);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_itoa(int n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dest, const void *src,
		int c, size_t size);
void					*ft_memchr(const void *str, int c, size_t n);
int						ft_memcmp(const void *str1, const void *str2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t size);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *str, int c);
void					ft_strclr(char *s);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **str);
char					*ft_strdup(const char *s);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlen(char const *str);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)
		(unsigned int, char));
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *haystack,
		const char *needle, size_t n);
char					*ft_strrchr(const char *str, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(char const *thehaystack, char const *needle);
char					*ft_strsub(char const *s, unsigned int
		start, size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_isupper(int c);
int						ft_islower(int c);
void					ft_strrev(char *s);
void					ft_chrswap(char *c, char *c2);
size_t					ft_strclen(char const *s, char c);
size_t					ft_word_count(char const *s, char delimiter);
char					*ft_shorttoa_base(short n, int base);
char					*ft_longlongtoa_base(long long n, int base);
char					*ft_itoa_base(int n, int base);
char					*ft_unsignedlltoa_base(unsigned long long n, int base);
char					*ft_dtoa(double d, int precision);
char					*ft_longdtoa(long double d, int precision);

					/* libft updates	*/

void					ft_lstPush( t_list **alst, void const *content, size_t content_size );
void					*ft_lstPop( t_list **alst );
void					lstMergeSort( t_list **node, int (*cmp)(void*, void*));
void					ft_lstreverse( t_list **node );
void					ft_lst_rm_if( t_list **node, int (*check)(void*), void (*del)(void*));
#endif
