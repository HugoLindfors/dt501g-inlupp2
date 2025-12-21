#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

// thresh (x, threshhold, min, max)
int thresh(int x, int t, int min, int max)
{
        // clang-format off
        if (x >= t) return max;
        else return min;
        // clang-format on
}

// copy file element (c, source file pointer, target, mode [(n)ormal, (t)reshhold])
void cfe(int c, FILE *sfp, char *tgt, char m)
{
        // clang-format off
        if (m == 't') for ((void)c; c > 0; c--) {
                char buffer[4];
                if (fscanf(sfp, "%3s", buffer)) sprintf(tgt, "%d", thresh(atoi(buffer), 120, 0, 255));
        } else for ((void)c; c > 0; c--) fscanf(sfp, "%3s", tgt);
        //clang-format on
}

// copy file (size, source file pointer, target file, mode [(n)ormal, (t)hreshold])
void cf(int sz, FILE *sfp, char **tf, char m)
{
        // clang-format off
        for (int i = 3; i < sz; i++) {
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

        const char *tgt = argv[1]; // tgt
        const char *src = argv[2]; // src

        FILE *sfp = fopen(src, "r");

        // clang-format off
        if (!sfp) {
                printf("invalid file argument\n");
                return 1;
        } // clang-format on

        char **tf = malloc(MAX * sizeof(char[4]));
        char tmp[3];

        cfe(2, sfp, tmp, 'n');
        int w = atoi(tmp);

        cfe(1, sfp, tmp, 'n');
        int h = atoi(tmp);

        int sz = w * h;

        cf(sz, sfp, tf, 't');

        // clang-format off
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) printf("%s ", tf[i * w + j + 3]);
                printf("\n");
        } // clang-format on

        return 0;
}