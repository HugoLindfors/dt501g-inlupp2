#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sq(double x)
{
        return pow(x, 2);
}

struct vec3
{
        double x, y, z;
};

typedef struct vec3 vec3_t;

double vec3len(vec3_t vec3)
{
        return sqrt(sq(vec3.x) + sq(vec3.y) + sq(vec3.z));
}

int main(int argc, char *argv[])
{
        double x = strtod(argv[1], NULL);
        double y = strtod(argv[2], NULL);
        double z = strtod(argv[3], NULL);

        vec3_t vec3;

        vec3.x = x;
        vec3.y = y;
        vec3.z = z;

        printf("%.6g", vec3len(vec3));
}