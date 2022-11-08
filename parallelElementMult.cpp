// #include <stdio.h>

// // deadling with creating child processes
// #include <sys/stat.h>
// #include <sys/wait.h>
// #include <errno.h>
// #include <fcntl.h>

// #include "SquareMatrixMultiplication.h"

// // timer
// #include <chrono>
// using namespace std::chrono;


// int* compute_row(int i, int dim, int** matrix_1, int** matrix_2)
// {
//     int * result_row;
//     for (int j = 0; j < dim ; j++){
//         result_row[j] = 0;
//         for (int k = 0; k < dim; k++){
//             result_row[j] += matrix_1[i][k] * matrix_2[k][j];
//         };
//     };
//     return result_row;
// };

// // operation using multi-processing
// SquareMatrix SquareMatrixMultiplication::parallel_element_computation(int p){
//     // p is the total number of child processes
//      // timer
//     // row_runtime = 0.0;
//     // clock_t begin = clock();
//     auto start = high_resolution_clock::now();

//     // get dimension of matrix
//     int dim = SquareMatrixMultiplication::get_dim();

//     // create a queue for each child process to dequeue
//     // dequeue to take the row index to compute 
//     // keep tracking of the parallel computation process
//     if (mkfifo("elem_queue", 0777) == -1){
//         if (errno != EEXIST){
//             printf("Cannot create fifo");
//             return SquareMatrix(dim, "set", 1);
//         }
//     }

//     int file_descriptor = open("elem_queue", O_RDWR);
//     if (file_descriptor == -1){
//         printf("Something wrong with accessing the queue");
//         return SquareMatrix(dim, "set", 2);
//     }
//     // put the index of row to the queue
//     // in the increase order
//     for (int i = 0; i < dim + p; i++){
//         int value = i;
//         // create a signal for the child process to exit
//         // when dequeing and receiving the value = -1
//         if (i >= dim){
//             value = -1;
//         }
//         if (write(file_descriptor, &value, sizeof(int)) == -1){
//             printf("Cannot enqueue");
//             return SquareMatrix(dim, "set", 3);
//         }; 
//     }

//     // create pipes to communicate between child and parent
//     // each pipe store the result of each row
//     // 1: write, only child process use this operation
//     // to write the result of row computation
//     // 0: read, only parent process use this operation
//     // to combine the result 
//     int fd[dim][2];
//     // initialize the pipes
//     for (int i = 0; i < dim; i++){
//         if (pipe(fd[i]) == -1){
//             perror("Something happens with pipe");
//         }
//     }

//     //---------CREATE CHILD PROCESS---------------
//     for (int i = 0; i < 10; i++){
//     // Only fork when in the main process - the parent process
//     // after the child complete the works
//     // kill it by the exit() function
//     // to make the fork() only for parent process
//         if (fork() == 0) {
//             // Get matrices a, b, and c

//             SquareMatrix object_matrix_a = SquareMatrixMultiplication::get_matrix_a();
//             SquareMatrix object_matrix_b = SquareMatrixMultiplication::get_matrix_b();

//             // int** result_matrix = object_row_matrix.get();
//             int** matrix_a = object_matrix_a.get();
//             int** matrix_b = object_matrix_b.get();

//             int l;
//             for (i = 0; i < dim; i++){
//                 if (read(file_descriptor, &l, sizeof(int)) == -1){
//                     printf("Something wrong with dequeue \n");
//                     return SquareMatrix(dim, "set", 4);
//                 };
//                 if (l == -1){
//                     // Receiving l = -1
//                     // a signal for child process to exit
//                     break;
//                 }
//                 // begin to process row l
//                 // parallel computation
//                 int * writer = compute_row(l, dim, matrix_a, matrix_b);

//                 if (write(fd[l][1], writer, sizeof(int) * dim) == -1){
//                     printf("An error occurs when writing to file descriptor \n");
//                 };
//                 close(fd[l][1]);
//             }
//             exit(0);
//         }
//     }

//     // wait all child processes to complete
//     while (wait(NULL) != -1 || errno != ECHILD);

//     // parent process aggerate the row computation
//     SquareMatrix object_row_matrix = SquareMatrixMultiplication::get_row_matrix();
//     int ** result = object_row_matrix.get();
//     for (int i = 0; i < dim; i++){
//         // close write opeartion
//         close(fd[i][1]);
//         int row[dim];
//         read(fd[i][0], row, sizeof(int) * dim);
//         close(fd[i][0]);

//         for (int j = 0; j < dim; j++){
//             result[i][j] = row[j];
//         }
//     }

//     // timer
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     SquareMatrixMultiplication::set_row_runtime(duration.count());

//     // cout << "\n Number of child process = " << p <<endl;

//     printf("\n------------------oOo-------------------");
//     printf("\nNumber of child processes: %d", p);
//     cout << "\nTotal Runtime of Parallel Row Computation: " << duration.count() << " microseconds " << endl;
//     printf("------------------oOo------------------- \n");

//     return SquareMatrixMultiplication::get_row_matrix();

// }
