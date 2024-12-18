#include "fdf.h"

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int to_walk(int n2, int n1)
{
    if (n2 > n1)
        return (1);
    return (-1);
}