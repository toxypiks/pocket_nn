#include <stdio.h>
#include <time.h>

#include "nn.h"

int main()
{
    size_t arch[] = {2, 2, 1};
    NN nn = nn_alloc(arch, ARRAY_LEN(arch));
    NN_PRINT(nn);

    return 0;

    srand(time(0));
    Mat a = mat_alloc(1, 2);
    mat_rand(a, 5, 10);

    float id_data[4] = {
        1, 0,
        0, 1
    };

    Mat b = {.rows = 2, .cols = 2, .es = id_data};

    Mat dst = mat_alloc(1,2);

    MAT_PRINT(a);
    printf("-----------------------\n");

    mat_dot(dst, a, b);
    MAT_PRINT(dst);

    return 0;
}
