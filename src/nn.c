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
    assert(a.cols == b.rows);
    size_t n = a.cols;
    assert(dst.rows == a.rows);
    assert(dst.cols == b.cols);
    for (size_t i = 0; i < dst.rows; ++i) {
        for (size_t j = 0; j < dst.cols; ++j) {
            MAT_AT(dst, i, j) = 0;
            for (size_t k = 0; k < n; ++k) {
                MAT_AT(dst, i, j) += MAT_AT(a, i, k)* MAT_AT(b, k, j);
            }
        }
    }
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
