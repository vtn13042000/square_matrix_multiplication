#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#include <string>

#include <sys/wait.h>


using namespace std;

int** generate(int dim, string option ="random")
{
// create a pointer to point to an array of pointer (size = rows )
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
            if (option == "random") {
            // generate a random value and assign it to the entry
                matrix[row][col] = rand() % 10;   
                } else{
                    if (option == "empty"){
                    matrix[row][col] = 0;   
                    }
                };
        }     
    }   
    return matrix;
};

int main(){

    int p = 10;
    int dim = 20;
    int fd[p][2];

    for (int i = 0; i < p; i++){
        // for (int j = 0; j < dim; j++){
        if (pipe(fd[i]) == -1){
            perror("Something happen with pipe");
        }
    // }
    }

    if (mkfifo("elem_queue", 0777) == -1){
        if (errno != EEXIST){
            printf("could not create fifo");
            return 1;
        }
    }

    int file_descriptor = open("elem_queue", O_RDWR);

    if (file_descriptor == -1){
        printf("Something wrong with the file_descriptor");
        return 1;
    }

    for (int i = 0; i < dim + p ; i++){
            if (i < dim){
                for (int j = 0; j < dim; j++){
                    int index[2] = {i, j};
                    if (write(file_descriptor, index, sizeof(int) * 2) == -1){
                        printf("cannot write");
                        return 1;
                        }; 
                    printf("wrote (%d, %d), from pid: %d, ppid: %d \n", i, j, getpid(), getppid());
                    }
    //         } else {
    //             if (i >= dim){
    //                 int signal[2] = {-1, -1};
    //                 if (write(file_descriptor, signal, sizeof(int) * 2) == -1){
    //                     printf("cannot write");
    //                     return 1;}
    //                 printf("wrote (%d, %d), from pid: %d, ppid: %d \n", signal[0], signal[1], getpid(), getppid());
    //         }
    }
    }

    // write exit signal
    for (int i = 0; i < p + 10; i++){
        // for (int j = 0; j < p; j++){
            int signal[2] = {-1, -1};
            // int index_x = signal[0];
            // int index_y = signal[1];
            if (write(file_descriptor, signal, sizeof(int) * 2) == -1){
                printf("cannot write");
                return 1;
                }; 
            printf("wrote (%d, %d), from pid: %d, ppid: %d \n", -1, -1, getpid(), getppid());
            // }
    }

    printf("-----------------\n");

    for (int i = 0; i < 10; i++){
        if (fork() == 0) {
            int arr_index[2];
            // arr_index = new int(2);
            // close read
            close(fd[i][0]);
            printf("i = %d, SUCCESS from process id: %d, parent id: %d \n", i, getpid(), getppid());
            for (i = 0; i < dim * dim; i++){
                if (read(file_descriptor, &arr_index, sizeof(int) * 2) <0){
                    printf("something wrong with reading the file descriptor \n");
                    // return 2;
                };
                int r = arr_index[0];
                int c = arr_index[1];
                if ((r == -1) && (c == -1)){
                    printf("Receiving (%d, %d) \n", r, c);
                    printf("A signal to break down \n");
                    break;
                }
                printf("received (%d, %d), from pid: %d, ppid: %d \n", r, c, getpid(), getppid());
                printf("Begin to process (%d, %d)\n", r, c);


                // // // begin to process row l
                // int writer[dim];
                int writer[3] = {r, c, 10};
                // writer = new int[dim];

                if (write(fd[i][1], writer, sizeof(int) * 3) == -1){
                    printf("An error occurs with write operation, pid: %d, ppid: %d\n", getpid(), getppid());
                    break;
                };
            
            }
            close(fd[i][1]);
            exit(0);
        }
    }

    for (int i = 0; i < p; i++){
        wait(NULL);
    }

    // while (wait(NULL) != -1 || errno != ECHILD);
    // close(file_descriptor);
    printf("-----------------\n");
    printf("Say Hello from parent process \n");
    printf("pid: %d, ppid: %d \n", getpid(), getppid());


    int ** checker = generate(dim, "empty");

    for (int i = 0; i < p; i++){
        for (int i = 0; i < dim * dim; i++){
        int reader[3];
        close(fd[i][1]);


        if (read(fd[i][0], &reader, sizeof(int) * 3) < 0){
            printf("reach the end \n");
            break;
        };
        int r = reader[0];
        int c = reader[1];
        int value = reader[2];
        printf("(%d, %d): %d \t", r, c, value);
        checker[r][c] = value;
        }
    }

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
                cout << checker[r][c];
            }else{
                cout << checker[r][c]<< "," ;
            }
        }

        if (r == (dim -1)) 
            cout << "]";
        else 
            cout << "]" << endl;
    }
    cout << "] \n" << endl;
    

    return 0;
}
