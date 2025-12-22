#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        for (int i = 4; i < sz + 4; i++) {
                char *xs = f[i];
                int x = atoi(xs);
                thresh(&x, t, m, M);
                sprintf(f[i], "%d", x);
        } // clang-format on
}

void cfe(FILE *sfp, char *te)
{
        fscanf(sfp, " %3s", te);
}

void cf(int sz, FILE *sfp, char **tf)
{
        // clang-format off
        for (int i = 4; i < sz + 4; i++) {
                tf[i] = malloc(sizeof(char[4]));
                cfe(sfp, tf[i]);
        } // clang-format on
}

int main(const int argc, const char **argv)
{
        // clang-format off
        if (argc < 3) return 1;
        // clang-format on

        const char *tgt = argv[1];
        const char *src = argv[2];

        FILE *sfp = fopen(src, "r");
        // clang-format off
        if (!sfp) return 1;
        // clang-format on

        char *tmp0 = malloc(sizeof(char[4]));
        cfe(sfp, tmp0);

        char *tmp1 = malloc(sizeof(char[4]));
        cfe(sfp, tmp1);
        int w = atoi(tmp1);

        char *tmp2 = malloc(sizeof(char[4]));
        cfe(sfp, tmp2);
        int h = atoi(tmp2);

        int sz = w * h;

        char **tf = malloc((sz + 4) * sizeof(char *));

        tf[0] = tmp0;
        tf[1] = tmp1;
        tf[2] = tmp2;

        tf[3] = malloc(sizeof(char[4]));
        cfe(sfp, tf[3]);

        cf(sz, sfp, tf);
        ta(sz, tf, 120, 0, 255);

        fclose(sfp);
        FILE *tfp = fopen(tgt, "w");

        fprintf(tfp, "%s\n%s %s\n%s\n", tf[0], tf[1], tf[2], tf[3]);

        // clang-format off
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        fprintf(tfp, "%s ", tf[i * w + j + 4]);
                } fprintf(tfp, "\n");
        } // clang-format on

        fclose(tfp);
        return 0;
}