//This Program was made by Samin Q on May 6th 2020
//Purpose is to use recursion to create a blob search function

#include <iostream> //Used for userinput
#include <vector> //Needed to make vector arrays
#include <stdlib.h> //needed for rand function
#include <time.h>   //needed for time; Primiary function is to gen. random numbers

using namespace std;

typedef vector <char> oneRow;     // One row of the matrix; each element is a char
typedef vector <oneRow> matrix; // A vector of vectors


void fillMatrix(matrix &grid){
    //Fills the vector 2D array
    //With either a * or blank-space
    
    //Each character is treated as a char
    //Any comparison is to be done with a char

    int randum; // used to determine what to fill the slot with; randomly generated
    
    //For Testing Purposes:
    //cout << "check 1\n";
    //cout << grid.size() << " nok\n";

    srand(time(NULL)); //Does stuff to get random numbers ¯\_(ツ)_/¯
    
    //We need to iterate through the list and fill it
    for (int i = 0; i < grid.size(); i++){
        
        for(int x = 0; x < grid[i].size(); x++){
            randum = 0 + (rand() % (1 - 0 + 1));

            if(randum == 1){
                grid[i][x] = '*';
            }

            else{
                grid[i][x] = ' ';
            }         
        }
    }

    return; //Good practice to return nothing in a void function
}

void displayGrid(matrix grid){
    //int nrow = grid.size(); Self note

    //Displays the matrix, with the rows going in descending order
    //grid is a matrix that is filled with 
    //randomly placed values of either * or a space

    for (int row = grid.size()-1; row > -1; row--){
        cout << row << " ";
        for(int column = 0; column < grid[row].size(); column++){
            cout << grid[row][column] << " ";
        }
        cout << "\n";
    }
    cout << "  ";

    //Prints the column numbers
    for(int i = 0; i < grid[0].size(); i++){
        cout << i << " ";
    }

    cout << "\n\n";
    return; //Good practice to return nothing in a void function
}

int blobcheck(matrix &grid, int checkrow, int checkcol){

    //Recursive function that checks for the size of a blob
    //grid is a matrix that is filled with 
    //randomly placed values of either * or a space

    //checkrow and checkcol are user provided
    //coords for the function to start it's search

    //int count = 0;
    //cout << checkrow << " " << checkcol << "\n";

    if (checkrow > grid.size()-1 || checkcol > grid[0].size()-1 || checkrow < 0 || checkcol < 0){
        return 0; //If the coords are off the grid, it has no-value, so we return a 0, as it doesn't affect the sum
    }

    else{

        if(grid[checkrow][checkcol] == ' '){
          return 0; // If the value is a space, so we return a 0, as it doesn't affect the sum

        }

        else{
            grid[checkrow][checkcol] = ' ';//Replace the value as to not double count it
            return 1 + blobcheck(grid, checkrow-1, checkcol-1) + blobcheck(grid, checkrow-1, checkcol) + blobcheck(grid, checkrow-1, checkcol+1)
            + blobcheck(grid, checkrow, checkcol-1) + blobcheck(grid, checkrow, checkcol+1)
            + blobcheck(grid, checkrow+1, checkcol-1) + blobcheck(grid, checkrow+1, checkcol) + blobcheck(grid, checkrow+1, checkcol+1);
        }
    }
}

int main(){
    int rows, colls; //User values to be used to generate the matrix
    char runloop = 'y'; //Used to determine if the user wants to continue looking for blobs
    
    //Userinput to get the matrix size
    cout << "Please enter number of rows: ";
    cin >> rows;
    cout << endl;
    cout << "Please enter number of collums: ";
    cin >> colls;
    
    cout << endl;

    matrix grid(rows, oneRow(colls));
    
    fillMatrix(grid);

    const matrix GRID_COPY = grid; //Makes a copy of the grid, as our method of looking for a blob size 
    //requires us altering the original matrix as to not double count
    //also is a const as the value never changes

    //We will ask the user once to check one coord, so we would use a do-while, as need it to happen once
    do{
        displayGrid(grid); //Displays the grid
        
        int checkrow, checkcol; //Userinput for values that blobcheck function will start it's search
            
        //Basic user input
        cout << "Please enter a row to check: ";
        cin >> checkrow;

        cout << "Please enter a collum to check: ";
        cin >> checkcol;
        
        cout << "The blob size is " << blobcheck(grid, checkrow, checkcol) << " at row: " << checkrow << " and column: " << checkcol << "\n\n";
        

        cout << "Would you like to continue (y/n): ";
        cin >> runloop; //We run the check once, after which the user can either choose to continue or exit
        
        cout << "\n\n";
        grid = GRID_COPY; // give the the grid the original matrix

    }while(runloop == 'y');


    return(0);

}