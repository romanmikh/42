# include "push_swap.h"

int is_within_int_range(const char* str) {
    const char* max_int_str = "2147483647";
    const char* min_int_str = "-2147483648";
    int len = strlen(str);
    int is_negative = (str[0] == '-');
    if (len > 10 + is_negative) return 0;
    if (is_negative) {
        if (len < 11) return 1;
        return strcmp(str, min_int_str) <= 0;
    } else {
        if (len < 10) return 1;
        return strcmp(str, max_int_str) <= 0;
    }
}

int arr_of_str_has_repeats(char* strings[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
int is_ordered(char *strings[], int length) {
    if (length < 2) {
        return 1;
    }
    int prev = atoi(strings[0]);
    for (int i = 1; i < length; i++) {
        int current = atoi(strings[i]);
        if (current < prev) {
            return 0;
        }
        prev = current;
    }
    return 1;
}
