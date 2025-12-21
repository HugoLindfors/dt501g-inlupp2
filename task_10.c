#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MX 1024

// thresh (x, threshhold, min, max)
int thresh(int x, int t, int mn, int mx)
{
        // clang-format off
        if (x >= t) return mx;
        else return mn;
        // clang-format on
}

// copy file element (c, source file pointer, target element, mode [(n)ormal, (t)reshhold])
void cfe(int c, FILE *sfp, char *te, char m)
{
        // clang-format off
        if (m == 't') for ((void)c; c > 0; c--) {
                fscanf(sfp, "%3s", te);
                sprintf(te, "%3d", thresh(atoi(te), 120, 0, 255));
        } else for ((void)c; c > 0; c--) fscanf(sfp, "%3s", te);
        //clang-format on
}

// copy file (size, source file pointer, target file, mode [(n)ormal, (t)hreshold])
void cf(int sz, FILE *sfp, char **tf, char m)
{
        // clang-format off
        for (int i = 0; i < sz; i++) {
                tf[i] = malloc(sizeof(char[4]));
                cfe(1, sfp, tf[i], m);
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

        char **tf = malloc(MX * sizeof(char[4]));

        cfe(1, sfp, tf[0], 'n');

        cfe(1, sfp, tf[1], 'n');
        int w = atoi(tf[1]);

        cfe(1, sfp, tf[2], 'n');
        int h = atoi(tf[2]);

        int sz = w * h;

        cf(sz, sfp, tf, 't');

        FILE *tfp = fopen(tgt, "w");

        fprintf(tfp, "%s\n%s %s", tf[0], tf[1], tf[2]);

        // clang-format off
        for (int i = 0; i < h; i++) {
                printf("ss");
                for (int j = 0; j < w; j++) {
                        if (!(i == h - 1 && j > w - 4)) fprintf(tfp, "%s ", tf[i * w + j + 3]);
                } fprintf(tfp, "\n");
        } // clang-format on

        fclose(tfp);

        return 0;
}