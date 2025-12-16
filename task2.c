#include <stdio.h>
#include <stdlib.h>

void sum(double a, double b, double *sumvptr)
{
        *sumvptr = a + b;
}

int main(int argc, char *argv[])
{

        double a = strtod(argv[1], NULL);
        double b = strtod(argv[2], NULL);
        double sumv;
        sum(a, b, &sumv);

        printf("%.g + %.g = %.g\n", a, b, sumv);

        return 0;
}