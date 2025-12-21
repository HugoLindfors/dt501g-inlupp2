#include <stdio.h>
#include <stdlib.h>

#define U_1_X 1
#define U_1_Y 2
#define U_1_Z 3
#define U_2_X 4
#define U_2_Y 5
#define U_2_Z 6

struct vec3
{
        double x, y, z;
};

typedef struct vec3 vec3_t;

vec3_t crossproduct(vec3_t u, vec3_t v)
{
        vec3_t uxv;

        uxv.x = (u.y * v.z) - (u.z * v.y);
        uxv.y = (u.z * v.x) - (u.x * v.z);
        uxv.z = (u.x * v.y) - (u.y * v.x);

        return uxv;
}

int main(int argc, const char **argv)
{
        vec3_t u, v;

        u.x = strtod(argv[U_1_X], NULL);
        u.y = strtod(argv[U_1_Y], NULL);
        u.z = strtod(argv[U_1_Z], NULL);

        v.x = strtod(argv[U_2_X], NULL);
        v.y = strtod(argv[U_2_Y], NULL);
        v.z = strtod(argv[U_2_Z], NULL);

        vec3_t uxv = crossproduct(u, v);

        printf("[%.6g, %.6g, %.6g]\n", uxv.x, uxv.y, uxv.z);

        return 0;
}