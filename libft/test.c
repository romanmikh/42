#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	// ft_atoi
	int atoi_result = ft_atoi("12345");
	printf("ft_atoi result: %d\n", atoi_result);

	// ft_isascii
	int is_ascii_result = ft_isascii('A');
	printf("ft_isascii result: %d\n", is_ascii_result);

	// ft_memcmp
	const char *str1 = "Hello";
	const char *str2 = "Hellp";
	int memcmp_result = ft_memcmp(str1, str2, 5);
	printf("ft_memcmp result: %d\n", memcmp_result);

	// ft_putendl_fd
	ft_putendl_fd("Testing ft_putendl_fd", 1);

	// ft_strdup
	const char *original_str = "Hello, World!";
	char *dup_str = ft_strdup(original_str);
	printf("ft_strdup result: %s\n", dup_str);
	free(dup_str);

	// ft_strlen
	const char *length_str = "Hello, World!";
	size_t str_length = ft_strlen(length_str);
	printf("ft_strlen result: %zu\n", str_length);

	// ft_strtrim
	const char *trim_str = "   Hello, World!   ";
	char *trimmed_str = ft_strtrim(trim_str, " ");
	printf("ft_strtrim result: \"%s\"\n", trimmed_str);
	free(trimmed_str);

	// ft_bzero
	char bzero_str[10] = "Hello";
	ft_bzero(bzero_str, 3);
	printf("ft_bzero result: \"%s\"\n", bzero_str);

	// ft_isdigit
	int isdigit_result = ft_isdigit('9');
	printf("ft_isdigit result: %d\n", isdigit_result);

	// ft_memcpy
	char src_memcpy[10] = "Hello";
	char dest_memcpy[10];
	ft_memcpy(dest_memcpy, src_memcpy, 3);
	printf("ft_memcpy result: \"%s\"\n", dest_memcpy);

	// ft_putnbr_fd
	ft_putnbr_fd(-12345, 1);

		// Function pointer type for ft_striteri
	void iteri_callback(unsigned int index, char *c) {
		// Example: Convert characters to uppercase every 2 indices
		if (index % 2 == 0) {
			*c = ft_toupper(*c);
		}
	}

	// Function pointer type for ft_strmapi
	char mapi_callback(unsigned int index __attribute__((unused)), char c) {
		// Example: Increment ASCII values by 1
		return c + 1;
	}


	// ft_striteri
	char striteri_str[10] = "Hello";
	ft_striteri(striteri_str, &iteri_callback);
	printf("ft_striteri result: \"%s\"\n", striteri_str);

	// ft_strmapi
	const char *mapi_str = "Hello";
	char *mapped_str = ft_strmapi(mapi_str, &mapi_callback);
	printf("ft_strmapi result: \"%s\"\n", mapped_str);
	free(mapped_str);

	// ft_substr
	const char *substr_str = "Hello, World!";
	char *sub_str = ft_substr(substr_str, 7, 5);
	printf("ft_substr result: \"%s\"\n", sub_str);
	free(sub_str);

	// ft_calloc
	size_t elem_size = sizeof(int);
	size_t num_elements = 5;
	int *calloc_arr = (int *)ft_calloc(num_elements, elem_size);
	printf("ft_calloc result: ");
	for (size_t i = 0; i < num_elements; ++i) {
		printf("%d ", calloc_arr[i]);
	}
	printf("\n");
	free(calloc_arr);

	// ft_isprint
	int isprint_result = ft_isprint('!');
	printf("ft_isprint result: %d\n", isprint_result);

	// ft_memmove
	char src_memmove[10] = "Hello";
	char dest_memmove[10];
	ft_memmove(dest_memmove, src_memmove, 3);
	printf("ft_memmove result: \"%s\"\n", dest_memmove);

	// ft_putstr_fd
	ft_putstr_fd("Testing ft_putstr_fd\n", 1);

	// ft_strjoin
	const char *join_str1 = "Hello, ";
	const char *join_str2 = "World!";
	char *joined_str = ft_strjoin(join_str1, join_str2);
	printf("ft_strjoin result: \"%s\"\n", joined_str);
	free(joined_str);

	// ft_strncmp
	const char *cmp_str1 = "Hello";
	const char *cmp_str2 = "Hellp";
	int strncmp_result = ft_strncmp(cmp_str1, cmp_str2, 5);
	printf("ft_strncmp result: %d\n", strncmp_result);

	// ft_tolower
	int tolower_result = ft_tolower('H');
	printf("ft_tolower result: %c\n", (char)tolower_result);

	// ft_isalnum
	int isalnum_result = ft_isalnum('A');
	printf("ft_isalnum result: %d\n", isalnum_result);

	// ft_itoa
	int num_itoa = -12345;
	char *itoa_str = ft_itoa(num_itoa);
	printf("ft_itoa result: %s\n", itoa_str);
	free(itoa_str);

	// ft_memset
	char memset_str[10] = "Hello";
	ft_memset(memset_str, 'X', 3);
	printf("ft_memset result: \"%s\"\n", memset_str);

	// ft_split
	const char *split_str = "Hello,World,Split";
	char **split_arr = ft_split(split_str, ',');
	printf("ft_split result: ");
	for (size_t i = 0; split_arr[i] != NULL; ++i) {
		printf("\"%s\" ", split_arr[i]);
		free(split_arr[i]);
	}
	printf("\n");
	free(split_arr);

	// ft_strlcat
	char dst_strlcat[20] = "Hello";
	const char *src_strlcat = ", World!";
	size_t dst_size = 20;
	size_t strlcat_result = ft_strlcat(dst_strlcat, src_strlcat, dst_size);
	printf("ft_strlcat result: \"%s\" (length: %zu)\n", dst_strlcat, strlcat_result);

	// ft_strnstr
	const char *strnstr_haystack = "Hello, World!";
	const char *strnstr_needle = "World";
	char *strnstr_result = ft_strnstr(strnstr_haystack, strnstr_needle, 20);
	printf("ft_strnstr result: \"%s\"\n", strnstr_result);

	// ft_toupper
	int toupper_result = ft_toupper('h');
	printf("ft_toupper result: %c\n", (char)toupper_result);

	// ft_isalpha
	int isalpha_result = ft_isalpha('A');
	printf("ft_isalpha result: %d\n", isalpha_result);

	// ft_memchr
	const char *memchr_str = "Hello, World!";
	const char *memchr_result = ft_memchr(memchr_str, 'W', 13);
	printf("ft_memchr result: %p\n", (void *)memchr_result);

	// ft_putchar_fd
	ft_putchar_fd('H', 1);

	// ft_strchr
	const char *strchr_str = "Hello, World!";
	char *strchr_result = ft_strchr(strchr_str, 'W');
	printf("ft_strchr result: \"%s\"\n", strchr_result);

	// ft_strlcpy
	char dst_strlcpy[20];
	const char *src_strlcpy = "Hello, World!";
	size_t strlcpy_result = ft_strlcpy(dst_strlcpy, src_strlcpy, sizeof(dst_strlcpy));
	printf("ft_strlcpy result: \"%s\" (length: %zu)\n", dst_strlcpy, strlcpy_result);

	// ft_strrchr
	const char *strrchr_str = "Hello, World!";
	char *strrchr_result = ft_strrchr(strrchr_str, 'o');
	printf("ft_strrchr result: \"%s\"\n", strrchr_result);

	return 0;
}