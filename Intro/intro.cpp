/*This program was made by someone.
It shows a simplistic CPP program*/

#include <iostream> // needed for input and output
using namespace std;

int main()
{
    int starting, ending;
    int stepval;
    double average;
    char choice = 'Y';

    cout << "This program finds the average of integers in a range\n\n";

    while (choice == 'Y' || choice == 'y') {
        //get a valid input from the user
        do {
            cout << "The starting integer must be smaller than the ending integer\n\n";
            cout << "Please enter the smallest value" << endl;
            cin >> starting;
            cout << "Please enter the largest value" << endl;
            cin >> ending;
            cout << endl;

        }while (starting > ending);

        //get a valid step value
        cout << "Please enter a step value" << endl;
        cin >> stepval;

        while (stepval <= 0){
            //Loops if the stepval is less than one
            cout << "Must be a positive step value" << endl;
            cin >> stepval;
        }

        //display the results
        cout << "Here are the numbers in the range:" << endl;
        int count = 0;
        int sum = 0;

        for (int i = starting; i <= ending; i += stepval){
            sum += i;
            count++;
            cout << i << " ";
        }

        cout << endl;

        if (count > 0){
            average = (double)sum/count;
            cout << "The average of the numbers is " << average << endl;
        }

        else{
            cout << "No numbers in the range No average calculated" << endl;
        }

        do{
            cout << "Would you like to do it again? (y/n)" << endl;
            cin >> choice;
        }while(choice != 'y' && choice != 'n');
    }
    return(0);
}
