#include <stdio.h>
#include <stdlib.h>

void print(double a, double b, double c)
{
        printf("%.6g %.6g %.6g\n", c, b, a);
}

int main(int argc, char *argv[])
{

        double a = strtod(argv[1], NULL);
        double b = strtod(argv[2], NULL);
        double c = strtod(argv[3], NULL);

        print(a, b, c);

        return 0;
}