#include <stdio.h>
#include <stdlib.h>

// The function reversesort manually sorts three elements in reverse order of size.
// Don't even try to make sense out of it. I will bring a flowchart to explain it.
double *reversesort(double *array)
{
        double temp0, temp1;

        // clang-format off
        if (array[0] < array[1] && array[0] < array[2]) {
          if (array[1] < array[2]) temp0 = array[0], array[0] = array[2], array[2] = temp0;
          else temp0 = array[0], array[0] = array[1], array[1] = array[2], array[2] = temp0;
        } else if (array[1] < array[0] && array[1] < array[2]) {
          if (array[0] < array[2]) temp0 = array[0], array[0] = array[2], temp1 = array[1], array[1] = temp0, array[2] = temp1;
          else temp1 = array[1], array[1] = array[2], array[2] = temp1;
        } else if (array[2] < array[0] && array[2] < array[1]) {
          if (array[0] < array[1]) temp0 = array[0], array[0] = array[1], array[1] = temp0;
        } // clang-format on

        return array;
}

int main(int argc, char const *argv[])
{
        double array[3];

        array[0] = strtod(argv[1], NULL);
        array[1] = strtod(argv[2], NULL);
        array[2] = strtod(argv[3], NULL);

        reversesort(array);

        // clang-format off
        for (int i = 0; i < 3; i += 1) printf("%g\n", array[i]);
        // clang-format on

        return 0;
}