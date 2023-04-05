#include "fill_array.h"
#include <cstdlib>
#include <ctime>

void fillArrayWithRandomNumbers(double arr[][COLS], int rows, int cols) {
    // seed random number generator
    srand(time(0));

    // fill array with random numbers between 0 and 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (double) rand() / RAND_MAX;
        }
    }
}
