#ifndef NN_H
#define NN_H

#include <stdlib.h>

/**
 * @defgroup Mat Matrix Functions
 * @brief Functions and macros for matrix operations
 */

/**
 * @brief Matrix structure used for neural network computations.
 *
 * Represents a 2D matrix stored in row-major order.
 */

typedef struct {
    size_t rows;
    size_t cols;
    size_t stride;
    float *es; // points to start value of matrix
} Mat;


/**
 * @brief Access an element of a matrix.
 *
 * @param m Matrix
 * @param i Row index
 * @param j Column index
 * @return Reference to element at (i, j)
 */
#define MAT_AT(m, i, j) (m).es[(i)*(m).stride + (j)] // put in parentheses in case of m, i or j being expressions e.g m + 1


/**
 * @brief Print matrix with its variable name.
 */
#define MAT_PRINT(m) mat_print(m, #m, 0)

/**
 * @brief Generate a random float between 0 and 1.
 */
float rand_float(void);

/**
 * @brief Sigmoid activation function.
 *
 * @param x Input value
 * @return Sigmoid of x
 */
float sigmoidf(float x);

/**
 * @brief Allocate a matrix with given dimensions.
 *
 * @param rows Number of rows
 * @param cols Number of columns
 * @return Allocated matrix
 */
Mat mat_alloc(size_t rows, size_t cols);

/**
 * @brief Fill matrix with random values in range [low, high].
 *
 * @param m Matrix
 * @param low Lower bound
 * @param high Upper bound
 */
void mat_rand(Mat m, float low, float high);

/**
 * @brief Get a view of a specific row.
 *
 * @param m Matrix
 * @param row Row index
 * @return Matrix view representing the row
 */
Mat mat_row(Mat m, size_t row);

/**
 * @brief Copy contents of one matrix to another.
 *
 * @param dst Destination matrix
 * @param src Source matrix
 */
void mat_copy(Mat dst, Mat src);

/**
 * @brief Fill matrix with a constant value.
 *
 * @param m Matrix
 * @param value Value to fill
 */
void mat_fill(Mat m, float value);

/**
 * @brief Matrix multiplication: dst = a * b
 *
 * @param dst Destination matrix
 * @param a Left operand
 * @param b Right operand
 */
void mat_dot(Mat dst, Mat a, Mat b);

/**
 * @brief Add matrix/vector to each row of dst.
 *
 * @param dst Destination matrix
 * @param a Matrix to add
 */
void mat_sum(Mat dst, Mat a);

/**
 * @brief Apply sigmoid function element-wise.
 *
 * @param m Matrix
 */
void mat_sig(Mat m);

/**
 * @brief Print matrix contents.
 *
 * @param m Matrix
 * @param name Name to display
 * @param padding Formatting padding
 */
void mat_print(Mat m, const char *name, size_t padding);

/**
 * @brief Get number of elements in a static array.
 */
#define ARRAY_LEN(xs) (sizeof(xs)/sizeof((xs)[0]))

/**
 * @defgroup NN Neural Network
 * @brief Functions and macros for neural network
 */

/**
 * @brief Neural network structure.
 *
 * Holds weights, biases, and activations for each layer.
 */
typedef struct {
    size_t count;
    Mat *ws;
    Mat *bs;
    Mat *as;
} NN;

/**
 * @brief Access input layer activations.
 */
#define NN_INPUT(nn) (nn).as[0]

/**
 * @brief Access output layer activations.
 */
#define NN_OUTPUT(nn) (nn).as[(nn).count]

/**
 * @brief Allocate a neural network.
 *
 * @param arch Array describing layer sizes
 * @param arch_count Number of layers
 * @return Allocated neural network
 */
NN nn_alloc(size_t *arch, size_t arch_count);

/**
 * @brief Print neural network structure.
 *
 * @param nn Neural network
 * @param name Name to display
 */
void nn_print(NN nn, const char *name);

/**
 * @brief Print neural network with variable name.
 */
#define NN_PRINT(nn) nn_print(nn, #nn);


/**
 * @brief Initialize neural network with random weights and biases.
 *
 * @param nn Neural network
 * @param low Lower bound
 * @param high Upper bound
 */
void nn_rand(NN nn, float low, float high);

/**
 * @brief Perform forward propagation.
 *
 * Computes activations layer by layer.
 *
 * @param nn Neural network
 */
void nn_forward(NN nn);
float nn_cost(NN nn, Mat ti, Mat to);
void nn_finite_diff(NN nn, NN g, float eps, Mat ti, Mat to);
void nn_learn(NN nn, NN g, float rate);

#endif // NN_H
