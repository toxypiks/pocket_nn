#ifndef NN_H
#define NN_H

#include <stdlib.h>

typedef struct {
    size_t rows;
    size_t cols;
    float *es; // points to start value of matrix
} Mat;

#define MAT_AT(m, i, j) (m).es[(i)*(m).cols + (j)] // put in parentheses in case of m, i or j being expressions e.g m + 1
#define MAT_PRINT(m) mat_print(m, #m)

float rand_float(void);
float sigmoidf(float x);

Mat mat_alloc(size_t rows, size_t cols);
void mat_rand(Mat m, float low, float high);
void mat_fill(Mat m, float value);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_sig(Mat m);
void mat_print(Mat m, const char *name);

#endif // NN_H
