#include <iostream>
#include <cmath>

using namespace::std;

bool isSafe(int mat[][9] , int i , int j ,int no , int n){

    //check for row and col
    for (int k = 0; k < n; k++) {
        if(mat[k][j] == no || mat[i][k] == no){
            return false;
        }
    }
    //check for subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for (int x = sx; x < sx + 3; x++) {
        for (int y = sy; y< sy + 3 ; y++) {
            if(mat[x][y] == no){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9] , int i , int j , int n){
    //base case
    if (i ==n){
        //print solution
        for (int x = 0; x < 9 ; x++) {
            for (int y = 0; y < 9 ; y++) {
                cout << mat[x][y] << "  ";
            }
            cout << "\n";
        }

        return true;
    }

    //rec case
    if(j == n){
        return solveSudoku(mat , i+1 , 0 , n);
    }
    //skip the prefilled cell
    if(mat[i][j] != 0){
        return solveSudoku(mat, i , j+1 , n);
    }

    //cell to be filled
    //try out all possibilities
    for (int k = 1; k <= n; k++) {
        //whether it is safe to place the number or not
        if(isSafe(mat , i , j , k ,n)){
            mat[i][j] = k;
            bool solveSubproblem = solveSudoku(mat , i , j + 1 , n);
            if(solveSubproblem){
                return  true;
            }
        }
    }
    //if no option works
    mat[i][j] = 0;
    return  false;
}

int main(int argc, char const *argv[])
{
    int n = 9;
    int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}

    };
    if (!solveSudoku(mat,0,0,n)){
        cout << "No solution exists!" << endl;
    }

    return 0;
}

