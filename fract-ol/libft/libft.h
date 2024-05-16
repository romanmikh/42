/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:48 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/15 14:54:28 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <stdbool.h>
# include <math.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_is_num(const char *n);
int		ft_is_double(const char *n);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		list_len_char(char a[]);
int		list_len_str(char *a[]);
int		isnum_from_str(const char *str);
int		list_repeat_check_int(int a[], int size);
int		list_repeat_check_str(char *a[], int size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_count_bits(unsigned char current_char);
int		find_max_in_list(int a[], int size);

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_int(int n);
int		ft_print_unsigned_dec(unsigned int n);
int		ft_print_unsigned_hex(unsigned int num, const char format);
int		ft_print_percent(void);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
double	ft_atof(const char *str);
long	ft_atol(const char *nptr);
int		ft_abs(int n);

# define TRUE 1
# define FALSE 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BWHI	"\033[1;37m"
# define MAG	"\033[0;35m"
# define BMAG	"\033[1;35m"
# define IMAG	"\033[3;35m"
# define BIMAG	"\033[1;3;35m"
# define RED	"\033[1;31m"
# define GRN	"\033[1;32m"
# define SBLU	"\033[5;3;34m"
# define DEF	"\033[0m"

#endif /* LIBFT_H */
