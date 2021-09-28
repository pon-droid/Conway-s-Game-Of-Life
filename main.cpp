#include <iostream>

using namespace std;


void dead_state(int board_state[][10]){
    for (int y = 0; y<10; y++){
            for (int x = 0; x<10; x++){
             board_state[x][y] = 0;
            }
    }
}





int main()
{

    //Creation of board state with 'random' values
    int board_state[10][10] = {
        {300,0,0,0,0,0,0,0,0,0} ,
        {0,250,0,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,2,0,0} ,
        {0,0,0,0,1,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,3,0,0} ,
        {0,0,0,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0,0,0,0} ,
    };
    //Set board state to 0
    dead_state(board_state);
    // Display board_state
    for (int y = 0; y<10; y++){
            for (int x = 0; x<10; x++){
             cout << board_state[x][y];
            }
    }
    return 0;
}
