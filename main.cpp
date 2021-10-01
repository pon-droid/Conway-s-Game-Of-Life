#include <iostream>
#include "unistd.h"

using namespace std;

const int B_WIDTH = 36;
const int B_HEIGHT = 143;

void next_board_state(int board_state[B_WIDTH][B_HEIGHT], int temp_board_state[B_WIDTH][B_HEIGHT]){
    //Copy board state to temporary board to get neighbour count from
    for(int i = 0; i < B_WIDTH; i++){
        for(int j = 0; j < B_HEIGHT; j++){
            temp_board_state[i][j] = board_state[i][j];
        }
    }

    for(int x = 0; x < B_WIDTH; x++){
        for(int y = 0; y < B_HEIGHT; y++){
            int neighbour_count = 0;


            //Get neighbour count relative to cell
            for(int row = -1; row<=1; row++){
                for(int col = -1; col<=1; col++){
                    int current_x = x + row;
                    int current_y = y + col;
                    //Conditons for which to NOT get neighbour count, (when out of range of board or same cell)
                    if (!(current_x < 0 || current_x >= B_WIDTH || current_y < 0 || current_y >= B_HEIGHT ||(row == 0 && col == 0))){
                       if(temp_board_state[current_x][current_y] == 1){
                           neighbour_count++;
                       }
                }
            }

        }
            //Apply rules of Conway's Game Of Life
            if(neighbour_count < 2){
                board_state[x][y] = 0;
            }
            if(neighbour_count == 3){
                board_state[x][y] = 1;
            }
            if(neighbour_count > 3){
                board_state[x][y] = 0;
            }
            if(temp_board_state[x][y] == 1 && neighbour_count == 2){
                board_state[x][y] = 1;
            }
    }
}
}

void print_board(int board_state[B_WIDTH][B_HEIGHT]){
    system("clear");
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             if(board_state[x][y] == 0){cout << " ";}
             else{cout << "\033[1;34m0\033[0m";}
            }
    cout << endl;
    }

}

void random_state(int board_state[B_WIDTH][B_HEIGHT]){
    for (int x = 0; x<B_WIDTH; x++){
            for (int y = 0; y<B_HEIGHT; y++){
             board_state[x][y] = rand() % 2;
            }
    }
}


int main()
{
    //Board_state
    int board_state[B_WIDTH][B_HEIGHT];
    //Temporary state to read off for update function
    int temp_board_state[B_WIDTH][B_HEIGHT];
    //Randomize board_state cells
    random_state(board_state);

    while(true){

        next_board_state(board_state,temp_board_state);

        print_board(board_state);
        //Delay terminal
        usleep(30000);
    }


    return 0;
}
