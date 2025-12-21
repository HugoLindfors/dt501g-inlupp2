#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// copy file element
void cfe(int c, FILE *fp, char *te)
{
        // clang-format off
        for ((void)c; c > 0; c--) fscanf(fp, "%3s", te);
        //clang-format on
}

// copy file
void cf(int sz, FILE *fp, char **f)
{
        // clang-format off
        for (int i = 3; i < sz; i++) {
                f[i] = malloc(101 * sizeof(char));
                cfe(1, fp, f[i]);
        } // clang-format on
        fclose(fp);
}

int main(const int argc, const char **argv)
{
        // clang-format off
        if (argc < 2) {
                printf("missing file argument\n");
                return 1;
        } else if (argc > 2) {
                printf("too many arguments\n");
                return 1;
        } // clang-format on

        const char *path = argv[1];
        FILE *fp = fopen(path, "r");

        // clang-format off
        if (!fp) {
                printf("invalid file argument\n");
                return 1;
        } // clang-format on

        char **f = malloc(255 * sizeof(char *));
        char tmp[3];

        cfe(2, fp, tmp);
        int w = atoi(tmp);

        cfe(1, fp, tmp);
        int h = atoi(tmp);

        int sz = w * h;

        cf(sz, fp, f);

        printf("%s\n", f[3]);
        printf("%s\n", f[sz - 1]);

        return 0;
}