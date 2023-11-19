int ft_countdigits(int n)
{
    int num_digits = 0;
    
    while(n != 0)
    {
        n /= 10;
        num_digits++;
    }
    return (num_digits);
}