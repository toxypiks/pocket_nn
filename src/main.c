#include <stdio.h>
#include <time.h>

#include "nn.h"

float td[] = {
    0, 0, 0,
    0, 1, 1,
    1, 0, 1,
    1, 1, 0,
};

int main()
{
    srand(time(0));
    //NN_PRINT(nn);

    size_t stride = 3;
    size_t n = sizeof(td)/sizeof(td[0])/stride;

    Mat ti = {
        .rows = n,
        .cols = 2,
        .stride = stride,
        .es = td
    };

    Mat to = {
        .rows = n,
        .cols = 1,
        .stride = stride,
        .es = td + 2,
    };

    size_t arch[] = {2, 2, 1};
    NN nn = nn_alloc(arch, ARRAY_LEN(arch));
    NN g = nn_alloc(arch, ARRAY_LEN(arch));
    nn_rand(nn, 0, 1);

    float eps = 1e-1;
    float rate = 1e-1;

    printf("cost = %f\n", nn_cost(nn, ti, to));
    nn_finite_diff(nn, g, eps, ti, to);
    nn_learn(nn, g, rate);
    printf("cost = %f\n", nn_cost(nn, ti, to));

    return 0;
}
