#include <stdio.h>
#include "nn.h"

int main()
{
    Mat m = mat_alloc(2, 2);
    mat_rand(m, 0, 10);
    mat_print(m);
}
