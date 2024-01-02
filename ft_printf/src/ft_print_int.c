int print_integer(int num) {
    int count = 0;
    if (num < 0) {
        putchar('-');
        num = -num;
        count++;
    }
    if (num / 10) {
        count += print_integer(num / 10);
    }
    putchar(num % 10 + '0');
    return count + 1;
}