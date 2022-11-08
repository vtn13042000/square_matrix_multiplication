#include <stdio.h>
#include <iostream>
#include <vector>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

#include "SquareMatrix.h"


using std::cout;
using std::endl;
using std::string;
using std::to_string;



class SquareMatrixMultiplication {
    private:
        // -------------VARIABLES----------
        SquareMatrix matrix_a, matrix_b;
        SquareMatrix sequent_matrix, row_matrix, element_matrix;
        double sequential_runtime, row_runtime, element_runtime;
        int dim;

        // --------------METHODS-------------
        // generate 2 square matrix with size = dim
        // all entries are random 
        // random value is within the range (0, 10)
        void poppulate(int dim)
        {
            SquareMatrix matrix_1 = SquareMatrix(dim);
            SquareMatrix matrix_2 = SquareMatrix(dim);
            SquareMatrix matrix_3 = SquareMatrix(dim, "empty");
        //    initialize random matrix a and b
            this->matrix_a = matrix_1;
            this->matrix_b = matrix_2;
        // initialize zero resul matrices 
            this->sequent_matrix = matrix_3;
            this->row_matrix = matrix_3;
            this->element_matrix = matrix_3;
        };
        
    public:
    //--------------CONSTRUCTOR------------
        SquareMatrixMultiplication(int dim ){
            this -> poppulate(dim);
            this->sequential_runtime = -1;
            this->row_runtime = -1;
            this->element_runtime = -1;
            this->dim = dim;
        };

    // initialize a blank object for the assigned task
        SquareMatrixMultiplication (){}

    //---------------GENERAL METHODS------------
    // Get dimension
        int get_dim(){
            return this->dim;
        };

    // Get dimension
    int set_dim(int d){
        return this->dim = d;
    };

    // ------------------ MATRIX -------------------
        // Get matrix
       SquareMatrix get_matrix_a(){
            return this-> matrix_a;
       };       
       SquareMatrix get_matrix_b(){
            return this-> matrix_b;
       };
        SquareMatrix get_sequent_matrix(){
            return this-> sequent_matrix;
       };
        SquareMatrix get_row_matrix(){
            return this-> row_matrix;
       };
        SquareMatrix get_element_matrix(){
            return this-> element_matrix;
       };

        // Set matrix
        void set_matrix_a(SquareMatrix matrix){
            this-> matrix_a = matrix;
        };       
        void set_matrix_b(SquareMatrix matrix){
            this-> matrix_b = matrix;
        };  
        void set_sequent_matrix(SquareMatrix matrix){
            this-> sequent_matrix = matrix;
        };  
        void set_row_matrix(SquareMatrix matrix){
            this-> row_matrix = matrix;
        };         
        void set_element_matrix(SquareMatrix matrix){
            this-> element_matrix = matrix;
        };  

    // ------------------ RUNTIME -------------------
        // Get runtime
        double get_sequent_runtime(){
            return this->sequential_runtime;
        };
        double get_row_runtime(){
            return this->row_runtime;
        };
        double get_element_runtime(){
            return this->element_runtime;
        };

        // Set runtime
        void set_sequent_runtime(double runtime){
            this->sequential_runtime = runtime;
        };
        void set_row_runtime(double runtime){
            this->row_runtime = runtime;
        };
        void set_element_runtime(double runtime){
            this->element_runtime = runtime;
        };

    // Cloning Method
        SquareMatrixMultiplication clone()
        {
            SquareMatrixMultiplication matrix_multiply = SquareMatrixMultiplication();
            matrix_multiply.set_dim(matrix_multiply.get_dim());
            matrix_multiply.set_matrix_a(SquareMatrixMultiplication::get_matrix_a());
            matrix_multiply.set_matrix_b(SquareMatrixMultiplication::get_matrix_b());
            matrix_multiply.set_sequent_matrix(SquareMatrixMultiplication::get_sequent_matrix());
            matrix_multiply.set_row_matrix(SquareMatrixMultiplication::get_row_matrix());
            matrix_multiply.set_element_matrix(SquareMatrixMultiplication::get_element_matrix());

            matrix_multiply.set_sequent_runtime(SquareMatrixMultiplication::get_sequent_runtime());
            matrix_multiply.set_row_runtime(SquareMatrixMultiplication::get_row_runtime());
            matrix_multiply.set_element_runtime(SquareMatrixMultiplication::get_element_runtime());

                return matrix_multiply;
        }

    //    MATRIX MULTIPLICATION APPRROACH
    //-------------Sequential Method--------------
    SquareMatrix sequential_computation();

    //--------------Parallel Methods ----------

    // ------------- Row Level -------------------
    SquareMatrix parallel_row_computation(int p);
    
    // ----------- Element Level ---------------
    SquareMatrix parallel_element_computation(int p);

    };

