#include <stdio.h>

typedef union
{
    struct {
        unsigned long long fraction : 52;
        unsigned exponent : 11;
        int sign : 1;
    } df;
    double d;
} du;

void print_bits(unsigned long long v, int width)
{
    char r[width + 1];
    for (int i = 0; i < width; r[i++] = '0');
    r[width] = '\0';

    while (width--)
    {
        if (v & 1)
            r[width] = '1';
        v >>= 1;
    }

    printf(r);
}

void println_double_fields(double d)
{
    du u;
    u.d = d;
    printf("S: %d\nE: %u (%d)\n", u.df.sign, u.df.exponent, u.df.exponent - 1023);
    printf("F: ");
    print_bits(u.df.fraction, 52);
    printf("\n");
}

int main(void)
{
    println_double_fields(2.5); 
    println_double_fields(1.15);
    println_double_fields(-2.25); 
    println_double_fields(1.375); 
    return 0;
}
