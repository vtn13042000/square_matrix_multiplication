// #include "SquareMatrixMultiplication.h"
// // #include "Matrices.h"


// #include <iostream>
// #include <iterator>

// using namespace std;


// // 1902060 - Vuong Thao Nguyen
// // CS401 : Assignment 1 - Matrix Multiplication
// // Emulate distributed system behavior in Parallel computing
// // fork() function to create multiple thread

// // implement on C++
// // run on wsl ubuntu.20-04 using vscode editer
// // 
// int main ()
// {
//     int dim = 100;
//     int p = 10;
//     SquareMatrixMultiplication matrix_multiply = SquareMatrixMultiplication(dim);
//     // SquareMatrix matrix_a = matrix_multiply.get_matrix_a();
//     // SquareMatrix matrix_b = matrix_multiply.get_matrix_b();

//     SquareMatrix result_matrix_1 = matrix_multiply.sequential_computation();
//     // result_matrix_1.print();

//     SquareMatrix result_matrix_2 = matrix_multiply.parallel_row_computation(p);
//     // result_matrix_2.print();

//     // SquareMatrix result_matrix_3 = matrix_multiply.parallel_element_computation(p);
//     // result_matrix_2.print();


//     return 0;

// }