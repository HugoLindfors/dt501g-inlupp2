#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ratio ratio_t;

struct img
{
        int mx;
        int h;
        int w;
        char path[100];
};

typedef struct img img_t;

// image thrasher by pointer
void itbp(const img_t *img_p, int c)
{
        printf("%d, ", c);
        printf("%dx%d\n", img_p->w, img_p->h);
        itbp(img_p, c + 1);
}

// image threasher by value
void itbv(img_t img, int c)
{
        printf("%d\n", c);
        printf("%dx%d\n", img.w, img.h);
        itbv(img, c + 1);
}

int main(const int argc, const char **argv)
{
        const char *mode = argv[1];

        img_t img;

        img.w = 16;
        img.h = 9;

        const img_t *img_p = &img;

        // clang-format off
        if (strcmp(mode, "--image-thrasher-by-pointer") || strcmp(mode, "-p")) itbp(img_p, 0);
        if (strcmp(mode, "--image-thrasher-by-value") || strcmp(mode, "-v")) itbv(img, 0);
        // clang-format on

        return 0;
}