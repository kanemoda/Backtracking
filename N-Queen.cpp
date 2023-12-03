#include <iostream>
#include <string>

using namespace::std;

void printBoard(int n, int board[][20]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
        
    }
    
}

bool canPlace(int board[][20] , int n , int i , int j){
    //Column
    for (int k = 0; k < i; k++)
    {
        if(board[k][j] ==1){
            return false;
        }
    }
    //Left Diagonal
    int a = i;
    int b = j;
    while (a >= 0 && b >= 0)
    {
        if (board[a][b] == 1)
        {
            return false;
        }
        a--; b--;
        
    }
    //Right Diagonal
    a = i;
    b = j;
    while (a >= 0 && b >= 0)
    {
        if(board[a][b] == 1){
            return false;
        }
        a--; b++;
    }
    return true;
}





bool solveNQueen(int n , int board[20][20],int i){
    //base case
    if(i == n){
        //print the board
        printBoard(n,board);

        return true;
    }
    //rec case
    for (int j = 0; j < n; j++)
    {
        //check wheter i,j is safe or not
        if(canPlace(board , n ,i , j)){
            board[i][j] = 1;
            bool success = solveNQueen(n , board , i+1);
            if(success){
                return true;
            }
            //BACKTRACK 
            board[i][j] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int board[20][20] = {0};
    int n;
    cout << "Please enter an input: ";
    cin >>n;
    solveNQueen(n,board,0);
    return 0;
}
