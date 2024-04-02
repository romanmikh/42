# include "libft.h"

int list_repeat_check_str(char *a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ft_strncmp(a[i], a[j], size) == 0) {
                return 1; // Found a repeating element
            }
        }
    }
    return 0; // No repeating elements found
}
