#include <stdio.h>
#include <stdlib.h>

double sum(double a, double b)
{
        return a + b;
}

int main(int argc, char *argv[])
{

        double a = strtod(argv[1], NULL);
        double b = strtod(argv[2], NULL);
        double sumv = sum(a, b);

        printf("%.g + %.g = %.g\n", a, b, sumv);

        return 0;
}