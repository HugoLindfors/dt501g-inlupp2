#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define X 0
#define Y 1
#define Z 2

struct vec3
{
        double x, y, z;
};

typedef struct vec3 vec3_t;

double vec3len(vec3_t u)
{
        return sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
}

int main(int argc, char const *argv[])
{
        vec3_t u;

        u.x = strtod(argv[X], NULL);
        u.y = strtod(argv[Y], NULL);
        u.z = strtod(argv[Z], NULL);

        double l = vec3len(u);

        printf("%.6g\n", l);

        return 0;
}