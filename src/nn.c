#include "nn.h"
#include <assert.h>
#include <stdio.h>

float rand_float(void)
{
    return (float) rand() / (float) RAND_MAX;
}

Mat mat_alloc(size_t rows, size_t cols)
{
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.es = malloc(sizeof(*m.es)*rows*cols);
    assert(m.es != NULL);
    return m;
}

void mat_rand(Mat m, float low, float high)
{
    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; ++j) {
            MAT_AT(m, i, j) = rand_float()*(high - low) + low;
        }
    }
}

void mat_fill(Mat m, float value)
{
    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; ++j) {
            MAT_AT(m, i, j) = value;
        }
    }
}

void mat_dot(Mat dst, Mat a, Mat b)
{
    (void) dst;
    (void) a;
    (void) b;
}
void mat_sum(Mat dst, Mat a)
{
    assert(dst.rows == a.rows);
    assert(dst.cols == a.cols);
    for (size_t i = 0; i < dst.rows; ++i) {
        for (size_t j = 0; j < dst.cols; ++j) {
            MAT_AT(dst, i, j) += MAT_AT(a, i, j);
        }
    }
}

void mat_print(Mat m)
{
    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; ++j) {
            printf("%f ", MAT_AT(m, i, j));
        }
        printf("\n");
    }
}
