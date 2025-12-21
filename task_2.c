#include <stdio.h>
#include <stdlib.h>

void sum(double *sigma, double a, double b)
{
        *sigma = a + b;
}

int main(int argc, char const *argv[])
{
        double a = strtod(argv[1], NULL);
        double b = strtod(argv[2], NULL);
        double sigma;
        double sigmaptr;

        sum(&sigma, a, b);
        printf("%.g\n", sigma);

        return 0;
}