#include "nn.h"
#include <assert.h>

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
void mat_print(Mat m)
{
    (void) m;
}
