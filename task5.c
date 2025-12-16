#include <stdio.h>
#include <stdlib.h>

struct vec3
{
        double x, y, z;
};

typedef struct vec3 vec3_t;

vec3_t vec3xprod(vec3_t u, vec3_t v)
{
        vec3_t w;

        w.x = (u.y * v.z) - (u.z * v.y);
        w.y = (u.z * v.x) - (u.x * v.z);
        w.z = (u.x * v.y) - (u.y * v.x);

        return w;
}

int main(int argc, char *argv[])
{
        double ux = strtod(argv[1], NULL);
        double uy = strtod(argv[2], NULL);
        double uz = strtod(argv[3], NULL);
        double vx = strtod(argv[4], NULL);
        double vy = strtod(argv[5], NULL);
        double vz = strtod(argv[6], NULL);

        vec3_t u;

        u.x = ux;
        u.y = uy;
        u.z = uz;

        vec3_t v;

        v.x = vx;
        v.y = vy;
        v.z = vz;

        vec3_t w = vec3xprod(u, v);

        printf("[%.6g, %.6g, %.6g]\n", w.x, w.y, w.z);
}