#include <iostream>

using namespace::std;

void generatingBrackets(int n , char *output , int remainingOpenBraceCount,int remainingCloseBraceCount){
    //base case
    if(remainingOpenBraceCount == 0 && remainingCloseBraceCount == 0){
        output[n*2] = '\0';
        cout << output << endl;
        return;
    }
    //recursive case
    //if equality happens
    if(remainingOpenBraceCount == remainingCloseBraceCount){
        output[n*2 - (remainingOpenBraceCount + remainingCloseBraceCount)] = '(';
        generatingBrackets(n , output , remainingOpenBraceCount - 1 , remainingCloseBraceCount);
    }
    /* else if (remainingOpenBraceCount > 0){
        output[n*2 - (remainingOpenBraceCount + remainingCloseBraceCount)] = '(';
        generatingBrackets(n , output , remainingOpenBraceCount - 1 , remainingCloseBraceCount);
    } 
    output[n*2 - (remainingOpenBraceCount + remainingCloseBraceCount)] = ')';
    generatingBrackets(n , output , remainingOpenBraceCount , remainingCloseBraceCount - 1); */

    else{
        if (remainingOpenBraceCount > 0)
        {
            output[n*2 - (remainingOpenBraceCount + remainingCloseBraceCount)] = '(';
            generatingBrackets(n , output , remainingOpenBraceCount - 1 , remainingCloseBraceCount);
        }
        
        

        output[n*2 - (remainingOpenBraceCount + remainingCloseBraceCount)] = ')';
        generatingBrackets(n , output , remainingOpenBraceCount , remainingCloseBraceCount - 1);
    }
}

int main(int argc, char const *argv[])
{
    char output[100];
    int n;
    cout << "Please enter a colum pair count: ";
    cin >> n;
    generatingBrackets(n,output,n,n);
    return 0;
}
