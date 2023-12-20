<h1 align="center">
	libft
</h1>

<p align="center">
	<b>Essential C Library project</b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/romanmikh/42?color=yellow" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/romanmikh/42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/romanmikh/42?color=yellow" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/romanmikh/42?color=yellow" />
</p>

<h3 align="center">
	<a href="#Overview">Overview</a>
	<span> · </span>
	<a href="#How-to-Use">How to Use</a>
	<span> · </span>
	<a href="#Testing">Testing</a>
</h3>

---
<a name="Overview"></a>
## 🧭 Overview

	🌟 Recreating fundamental C functions for future project use 🌟

### Functions from `<ctype.h>` library

* [`ft_isascii`](libft/src/ft_isascii.c)			- ASCII character verification.
* [`ft_isalnum`](libft/src/ft_isalnum.c)			- alphanumeric character check.
* [`ft_isalpha`](libft/src/ft_isalpha.c)			- alphabetic character check.
* [`ft_isdigit`](libft/src/ft_isdigit.c)			- decimal-digit character check.
* [`ft_isprint`](libft/src/ft_isprint.c)			- printable character check (includes space).
* [`ft_tolower`](libft/src/ft_tolower.c)			- convert upper case to lower case.
* [`ft_toupper`](libft/src/ft_toupper.c)			- convert lower case to upper case.

### Functions from `<stdlib.h>` library

* [`ft_atoi`](src/to/ft_atoi.c)		- ASCII to integer conversion.
* [`ft_calloc`](libft/src/ft_calloc.c)	- allocate memory.

### Functions from `<strings.h>` library

* [`ft_bzero`](libft/src/ft_bzero.c)		- zero a byte string.
* [`ft_memset`](libft/src/ft_memset.c)		- fill a byte string with a byte.
* [`ft_memchr`](libft/src/ft_memchr.c)		- locate a byte in a byte string.
* [`ft_memcmp`](libft/src/ft_memcmp.c)		- compare byte strings.
* [`ft_memmove`](libft/src/ft_memmove.c)	- move a byte string.
* [`ft_memcpy`](libft/src/ft_memcpy.c)		- copy memory area.

### Functions from `<string.h>` library

* [`ft_strlen`](libft/src/ft_strlen.c)				- calculate string length.
* [`ft_strchr`](libft/src/ft_strchr.c)				- find character in string (first occurrence).
* [`ft_strrchr`](libft/src/ft_strrchr.c)			- find character in string (last occurrence).
* [`ft_strnstr`](libft/src/ft_strnstr.c)			- bounded substring search in string.
* [`ft_strncmp`](libft/src/ft_strncmp.c) *		- bounded string comparison.
* [`ft_strnrcmp`](libft/src/ft_strnrcmp.c)		- reverse bounded string comparison.
* [`ft_strdup`](libft/src/ft_strdup.c)				- duplicate string with allocation.
* [`ft_strlcpy`](libft/src/ft_strlcpy.c)			- size-bounded string copying.
* [`ft_strlcat`](libft/src/ft_strlcat.c)			- size-bounded string concatenation.

### Non-standard functions

* [`ft_putchar_fd`](libft/src/ft_putchar_fd.c)		- output a character to given file.
* [`ft_putstr_fd`](libft/src/ft_putstr_fd.c)		- output string to given file.
* [`ft_putendl_fd`](libft/src/ft_putendl_fd.c)		- output string to given file with newline.
* [`ft_putnbr_fd`](libft/src/ft_putnbr_fd.c)		- output integer to given file.
* [`ft_itoa`](libft/src/ft_itoa.c)					- convert integer to ASCII string.
* [`ft_substr`](libft/src/ft_substr.c)				- extract substring from string.
* [`ft_strtrim`](libft/src/ft_strtrim.c)			- trim beginning and end of string with the specified characters.
* [`ft_strjoin`](libft/src/ft_strjoin.c)			- concatenate two strings into a new string (with malloc).
* [`ft_split`](libft/src/ft_split.c)				- split string, with specified character as delimiter, into an array of strings.
* [`ft_strmapi`](libft/src/ft_strmapi.c)			- create new string from modifying string with specified function.

_Note: Functions indicated with an asterisk (*) are additional, not obligatory for the project._

<a name="How-to-Use"></a>
## 🚀 How to Use

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1: Compiling the library**

To compile the library, run:

```shell
$ cd path/to/libft && make
```

**2: Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "libft.h"
```

and, when compiling your code, add the required flags:

```shell
-lft -L path/to/libft.a -I path/to/libft.h
```

<a name="Testing"></a>
## 💯 Testing

### Third party testers used:

* [0x050f/libft-war-machine](https://github.com/0x050f/libft-war-machine)
* [Tripouille/libftTester](https://github.com/Tripouille/libftTester)
* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)
