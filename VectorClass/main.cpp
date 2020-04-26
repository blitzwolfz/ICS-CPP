//This program was made by Samin Q to implement random numbers using vector arrays
//Was made on April 24th

#include <iostream>
#include <vector>
#include <stdlib.h> //needed for rand function
#include <time.h>   //needed for time to gen. random numbers

using namespace std; // needed for output
typedef vector<int> intarray;

const int MAXRANGE = 75; // Max range of the array
const int MINRANGE = -25; // Min range of the array
//const int MAXSIZE = 30; 

void FillArray(intarray &lst, int MAXRANGE, int MINRANGE){
    //fills up the array
    //lst is the vector array

    srand(time(NULL));
    int randum;
    for (int i = 0; i < lst.size(); i++)
    {
        randum = MINRANGE + (rand() % (MAXRANGE - MINRANGE + 1));
        lst[i] = randum;
    }
    return;
}

void Display(const intarray &lst){
    //this function display the array given
    // lst is the array
    
    cout << "Here is your list: \n";
    cout << "Slot number\t|\tContent\n";
    
    for (int i = 0; i < lst.size(); i++)
    {
        cout << "\t" << i+1 << "\t|\t" << lst[i];
        cout << endl;
    }

    return;
}

void Average(const intarray &lst){
    //Finds the average sum of the array
    //averagesum adds up all the numbers in the array
    
    int averagesum = 0; // holds the the total sum of all the numbers in the Vector Array

    for (int i = 0; i < lst.size(); i++)
    {
        averagesum += lst[i];
        //cout << averagesum << endl;
    }
    
    cout << endl;
    cout << "The average sum of the numbers in the list is " << averagesum / lst.size();
}

int main(){
    
    int maxsize; //Total number of slots in an array

    cout << "How large do you want the vector to be: "; 
    cin >> maxsize;

    intarray numbers(maxsize); //Vector array

    FillArray(numbers, MAXRANGE, MINRANGE);
    Display(numbers);
    Average(numbers);
    cin >> maxsize;

    return (0);
}
