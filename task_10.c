#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void thresh(int *x, int t, int m, int M)
{
        // clang-format off
        if (*x >= t) *x = M;
        else *x = m;
        // clang-format on
}

void ta(int sz, char **f, int t, int m, int M)
{
        // clang-format off
        for (int i = 3; i < sz; i++) {
                char *xs = f[i];
                int x = atoi(xs);
                thresh(&x, t, m, M);
                sprintf(f[i], "%d", x);
        } // clang-format on
}

void cfe(int c, FILE *sfp, char *te)
{
        // clang-format off
        for ((void)c; c > 0; c--) fscanf(sfp, "%3s", te);
        //clang-format on
}

void cf(int sz, FILE *sfp, char **tf)
{
        // clang-format off
        for (int i = 0; i < sz; i++) {
                tf[i] = malloc(sizeof(char[4]));
                cfe(1, sfp, tf[i]);
        } // clang-format on
        fclose(sfp);
}

int main(const int argc, const char **argv)
{
        // clang-format off
        if (argc < 2) {
                printf("missing file arguments\n");
                return 1;
        } else if (argc == 2) {
                printf("too few file arguments\n");
                return 1;
        } else if (argc > 3) {
                printf("too many arguments\n");
                return 1;
        } // clang-format on

        const char *tgt = argv[1];
        const char *src = argv[2];

        FILE *sfp = fopen(src, "r");

        // clang-format off
        if (!sfp) {
                printf("invalid file argument\n");
                return 1;
        } // clang-format on

        char **tf = malloc(MAX * sizeof(char[4]));

        cfe(1, sfp, tf[0]);

        cfe(1, sfp, tf[1]);
        int w = atoi(tf[1]);

        cfe(1, sfp, tf[2]);
        int h = atoi(tf[2]);

        int sz = w * h;

        cf(sz, sfp, tf);
        ta(sz, tf, 120, 0, 255);

        FILE *tfp = fopen(tgt, "w");

        fprintf(tfp, "%s\n%s %s", tf[0], tf[1], tf[2]);

        // clang-format off
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        if (!(i == (h - 1) && j > (w - 4))) fprintf(tfp, "%s ", tf[i * w + j + 3]);
                } fprintf(tfp, "\n");
        } // clang-format on

        fclose(tfp);

        return 0;
}