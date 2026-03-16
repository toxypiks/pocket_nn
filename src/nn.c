#include "nn.h"
#include <assert.h>
#include <stdio.h>

Mat mat_alloc(size_t rows, size_t cols)
{
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.es = malloc(sizeof(*m.es)*rows*cols);
    assert(m.es != NULL);
    return m;
}

void mat_dot(Mat dst, Mat a, Mat b)
{
    (void) dst;
    (void) a;
    (void) b;
}
void mat_sum(Mat dst, Mat a)
{
    (void) dst;
    (void) a;
}

#define MAT_AT(m, i, j) (m).es[(i)*(m).cols + (j)] // put in parentheses in case of m, i or j being expressions e.g m + 1

void mat_print(Mat m)
{
    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; ++j) {
            printf("%f ", MAT_AT(m, i, j));
        }
        printf("\n");
    }
}
