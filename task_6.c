#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isrhyme(const char *string_1, const char *string_2)
{
        int length_1 = strlen(string_1), length_2 = strlen(string_2);

        // clang-format off
        // If the string are not at least three characters it's meaningless to check.
        if (length_1 < 3 || length_2 < 3) return false;
        // clang-format on

        const char *end_1 = string_1 + (length_1 - 3);
        const char *end_2 = string_2 + (length_2 - 3);

        return !strcmp(end_1, end_2);
}

int main(int argc, char const *argv[])
{
        bool rhyme = isrhyme(argv[1], argv[2]);
        char const *string_1 = argv[1], *string_2 = argv[2];

        // clang-format off
        if (rhyme) printf("ja\n");
        else printf("nej\n");
        // clang-format on

        return 0;
}