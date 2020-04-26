//This program was made by Samin Q to implement random numbers

#include <iostream> //idk?
#include <stdlib.h> //needed for rand function
#include <time.h> //needed for time to gen. random numbers

using namespace std; // needed for output

const int MAXRANGE = 75; // Max range of the array
const int MINRANGE = -25; // Min range of the array
const int MAXSIZE = 30; //Total number of slots in an array

void FillArray(int lst[], int maxrange, int minrange) {
    //fills up the array
    //lst is the array
	srand(time(NULL));
	int randum;
	for (int i = 0; i <= 30; i++) {
		randum = minrange + (rand() % (maxrange - minrange + 1));
		lst[i] = randum;
	}
	return;
}

void Display(int lst[], int maxsize) {
    //this function display the array given
    // lst is the array
    cout << "Here is your list: \n";
    cout << "Slot number\t|\t Content\n";
	for (int i = 0; i <= maxsize - 1; i++) {
		cout << i << "\t|\t" << lst[i];
		cout << endl;
	}
	return;
}

int main() {
    //numbers is the array
	int numbers[MAXSIZE];
	FillArray(numbers, MAXRANGE, MINRANGE);
	Display(numbers, MAXSIZE);
	return(0);

}
