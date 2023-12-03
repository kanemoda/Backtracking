#include <iostream>
#include <string>

using namespace::std;

void findSubsets(char *input, char *output, int i , int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        if (output[0] == '\0')
        {
            cout << "NULL";
        }
        
        cout << output << "\n";
        return;
    }

    //recursive case
    //Include the ith letter
    output[j] = input[i];
    findSubsets(input , output , i+1 , j+1);
    //Exclude the ith letter
    //Overwriting
    findSubsets(input , output , i+1 , j); 
}

int main(int argc, char const *argv[])
{
    char input[100];
    char output[100];
    cout << "Finding Subsets:\n";
    


    cin >> input;
    findSubsets(input , output , 0 , 0);
    return 0;
}
