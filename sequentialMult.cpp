#include <stdio.h>

// timer
#include <chrono>
using namespace std::chrono;

#include "SquareMatrixMultiplication.h"


// sequential matrix multiplication
SquareMatrix SquareMatrixMultiplication::sequential_computation(){
    // timer
    auto start = high_resolution_clock::now();

    // access the matrix A and matrix B and dimension
    int dimension = SquareMatrixMultiplication::dim; 
    SquareMatrix object_matrix_1 = SquareMatrixMultiplication::get_matrix_a();
    SquareMatrix object_matrix_2 = SquareMatrixMultiplication::get_matrix_b();
    SquareMatrix object_sequent_matrix = SquareMatrixMultiplication::get_sequent_matrix();

    // get the matrix from SquareMatrix object
    int** sequent_matrix = object_sequent_matrix.get();
    int** matrix_1 = object_matrix_1.get();
    int** matrix_2 = object_matrix_2.get();

    // computing elements in sequential order
    for (int i = 0 ; i < dimension; i ++) {
        for (int j = 0 ; j < dimension; j++){
            sequent_matrix[i][j] = 0;

            for (int k = 0; k < dimension ; k ++) {
                sequent_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    // timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    SquareMatrixMultiplication::set_sequent_runtime(duration.count());
    
    printf("\n------------------oOo-------------------");
    cout << "\nTotal Runtime of Sequential Computation:  " << duration.count() << " microseconds" << endl;
    printf("------------------oOo------------------- \n");


    return SquareMatrixMultiplication::get_sequent_matrix();

};
