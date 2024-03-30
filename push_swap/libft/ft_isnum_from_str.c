/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum_from_str.c                                :+:      :+:    :+:   */
/*                                                     :+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:27 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:27 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int isnum_from_str(const char *str) {
    // Check for null pointer or empty string
    if (str == NULL || *str == '\0') {
        return (0);
    }

    // Check for optional leading sign
    if (*str == '-' || *str == '+') {
        str++; // Skip the sign
        if (*str == '\0') { // String is just "-" or "+"
            return (0);
        }
    }

    // Check each character to ensure it's a digit
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return (0);;
        }
        str++;
    }

    return (1);
}
