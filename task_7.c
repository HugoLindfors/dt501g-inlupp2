#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringcopy(char *target, const char *source)
{
        size_t length = strlen(source);
        // clang-format off
        for (int i = 0; i < length; i++) target[i] = source[i];
        // clang-format on
        return 0;
}

int main(int argc, const char **argv)
{
        char *target = malloc(10);

        // stringcopy(target, argv[1]);

        char *source = malloc(10);
        scanf("%s", source);

        stringcopy(target, source);

        printf("%s %s\n\n", target, target);

        return 0;
}