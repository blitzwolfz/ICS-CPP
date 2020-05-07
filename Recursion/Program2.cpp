//Made by Samin Q, on April 29th
//Implements Recursion to find a term in Pascal's triangle

#include <iostream>
using namespace std;

int pascal(int row, int col){
    // row is an input number for row in Pascal's triangle
    //Col is an input number for collum in Pascal's triangle
    if (col == 0 || col == row ){
        return 1;
    }

    else{
        return pascal(row - 1, col - 1) + pascal(row - 1, col);
    }
}

int main(){
    // row is an input number for row in Pascal's triangle
    //Collum is an input number for collum in Pascal's triangle
    int row, collum; 

    cout << "Please enter a Row: ";
    cin >> row;

    cout << "Please enter another Collum: ";
    cin >> collum;

    cout << endl;

    if(row < collum){
        cout << "Calculation Error, collum cannot be greater than row.";
    }

    else{
        cout << "The term for " << row << " and " << collum << " is " << pascal(row, collum) << endl;
    }

    //cin >> row;
    return (0);
}