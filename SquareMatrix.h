#include <stdio.h>
#include <iostream>
#include <vector>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>


using std::cout;
using std::endl;
using std::string;
using std::to_string;



class SquareMatrix {
    private:
        // -------------VARIABLES----------
        int** matrix;
        int DIM;

        // --------------METHODS-------------
        // generate a square matrix with size = dim 
        // all entries are random 
        // random value is within the range (0, 10)
        int** generate(int dim, string option ="random", int value = 0)
        {
        // create a pointer to point to an array of pointer (size = rows)
            int** matrix ;
            matrix = new int*[dim];
            // generate random value for each entry in the matrix
            // iterate per row
            for (int row = 0; row < dim;  row++) {
                // create an actual array that store value in each entry
                matrix[row] = new int[dim];
                // if (option == "random")
                    // interate per element in each row
                for (int col = 0; col < dim;  col++) {
                    // generate a random value and assign it to the entry
                    if (option == "random") {
                        matrix[row][col] = rand() % 10;   
                        } else{
                    // Assign all entries = 0
                         if (option == "empty"){
                            matrix[row][col] = 0;   
                         } else {
                    // Assign all entries = value
                        if (option == "set"){
                            matrix[row][col] = value;   
                        }
                         }
                        };
                }     
            }   
            return matrix;
        };
        

    public:

        //--------------CONSTRUCTOR------------
        SquareMatrix(int dim, string option = "random", int value = 0){
            DIM = dim;
            matrix = this -> generate(dim, option, value);
        };

        // create blank SquareMatrix for the assign task
        SquareMatrix(){
        };

        //---------------GENERAL METHODS------------
        int get_dim (){
            return this -> DIM;
        };

        // -------Matrix---------
        // get the pointer to the matrix
        int ** get()
        {
            return SquareMatrix::matrix;
        };
        // set the pointer to the matrix
        void set_matrix(int** computed_matrix){
            this->matrix = computed_matrix;
        }

        void print(){
            print(this -> DIM, this -> matrix);
        };

        void print(int dim, int** matrix)
        {
            cout << "\n[" ;
            // iterate each row
            for (int r = 0; r < dim; r ++ ){
            // rows have to have lower level 
                if (r > 0){
                    cout << " " ;
                }
                cout << "[" ;
                // iterate per entry in each row
                for (int c = 0; c < dim; c++){
                    if (c == (dim -1)){
                        cout << matrix[r][c];
                    }else{
                        cout << matrix[r][c]<< "," ;
                    }
                }

                if (r == (dim -1)) 
                    cout << "]";
                else 
                    cout << "]" << endl;
            }
            cout << "] \n" << endl;
        };
    };

