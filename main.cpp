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

int next_board_state(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    int count = 0;
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
               for(int row = -1; row<= 1; row++){
                 for(int col = -1; col<= 1; col++){
                     int current_x = x + row;
                     int current_y = y + col;
                     if (current_x >= 0 && current_x < B_WIDTH && current_y >= 0 && current_y < B_HEIGHT){
                        if(board_state[current_x][current_y] == 1){
                            count++;
                        }
                     }
                 }
             }
         }
    }
    return count;
}


void print_board(int** board_state, const int B_WIDTH, const int B_HEIGHT){
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             if(board_state[x][y] == 0){cout << ' ';}
             else{cout << '#';}
            }
            cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    const int B_WIDTH = 10;
    const int B_HEIGHT = 10;

    // Create 2D pointer array

    int** board_state = allocate_board(B_WIDTH, B_HEIGHT);

    // Initialise whole array with value 0

    dead_state(board_state, B_WIDTH, B_HEIGHT);

    print_board(board_state, B_WIDTH, B_HEIGHT);
    cout << endl;

    // Randomize board between 0 and 1

    random_state(board_state, B_WIDTH, B_HEIGHT);

    print_board(board_state, B_WIDTH, B_HEIGHT);

    cout << "=================================================" << endl;
    //Counts the living neighbours of every alive cell
    cout << next_board_state(board_state, B_WIDTH, B_HEIGHT);


    // Deallocate memory

    for(int i = 0; i < B_WIDTH; i++){
    delete[] board_state[i];
    }
    delete[] board_state;

    return 0;
}
