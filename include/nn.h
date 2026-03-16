#ifndef NN_H
#define NN_H

#include <stdlib.h>

typedef struct {
    size_t rows;
    size_t cols;
    float *es; // points to start value of matrix
} Mat;

Mat mat_alloc(size_t rows, size_t cols);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_print(Mat m);

#endif // NN_H
