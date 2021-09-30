#include <iostream>
#include <time.h>

using namespace std;
//[DONE]TODO: This only works with square board sizes

int** allocate_board(const int B_WIDTH, const int B_HEIGHT){

    int** board_state = new int*[B_WIDTH];

    for (int i = 0; i < B_WIDTH; i++) {

        // Declare a memory block
        // of size B_HEIGHT
        board_state[i] = new int[B_HEIGHT];
    }

    return board_state;
}

void dead_state(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             board_state[x][y] = 0;
            }
    }
}

void random_state(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             board_state[x][y] = rand() % 2;
            }
    }
}

void print_board(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             cout << board_state[x][y];
            }
    }
}

int main()
{
    srand(time(NULL));
    const int B_WIDTH = 3;
    const int B_HEIGHT = 4;

    // Create 2D array by passing a pointer to a pointer

    int** board_state = allocate_board(B_WIDTH, B_HEIGHT);

    // Initialise whole array with value 0 for memory safety

    dead_state(board_state, B_WIDTH, B_HEIGHT);

    print_board(board_state, B_WIDTH, B_HEIGHT);
    cout << endl;

    // Randomize board between 0 and 1

    random_state(board_state, B_WIDTH, B_HEIGHT);

    print_board(board_state, B_WIDTH, B_HEIGHT);

    // Deallocate memory

    for(int i = 0; i < B_WIDTH; i++){
    delete[] board_state[i];
    }
    delete[] board_state;

    return 0;
}
