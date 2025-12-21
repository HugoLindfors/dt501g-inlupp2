#include <stdio.h>
#include <stdlib.h>

double sum(double a, double b)
{
        return a + b;
}

int main(int argc, char const *argv[])
{
        double a = strtod(argv[1], NULL);
        double b = strtod(argv[2], NULL);

        printf("%.g\n", sum(a, b));

        return 0;
}