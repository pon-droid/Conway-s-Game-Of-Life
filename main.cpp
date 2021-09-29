#include <iostream>

using namespace std;
//TODO: This only works with square board sizes

int** allocate_board(const int B_WIDTH, const int B_HEIGHT ){

    int** board_state = new int*[B_WIDTH];
    for (int i = 0; i < B_HEIGHT; ++i)
    {
       board_state[i] = new int[B_HEIGHT];
    }
    return board_state;
}

void dead_state(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int x = 0; x<B_HEIGHT; x++){
            for (int y = 0; y<B_WIDTH; y++){
             board_state[x][y] = 0;
            }
    }
}

void print_board(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int y = 0; y<B_HEIGHT; y++){
            for (int x = 0; x<B_WIDTH; x++){
             cout << board_state[x][y];
            }
    }
}

int main()
{
    const int B_WIDTH = 10;
    const int B_HEIGHT = 10;

    // Create 2D array by passing a pointer to a pointer
    int** board_state = allocate_board(B_WIDTH, B_HEIGHT);
    // Initialise whole array with value 0 for memory safety
    dead_state(board_state, B_WIDTH, B_HEIGHT);
    // Output array
    print_board(board_state, B_WIDTH, B_HEIGHT);
    // Deallocate memory
    delete[] board_state;
    return 0;
}
