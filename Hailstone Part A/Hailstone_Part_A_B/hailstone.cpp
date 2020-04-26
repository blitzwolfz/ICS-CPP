/* This program was made by Samin Q on
Feburary 4th. This program is an implemantation
of Hailstone Numbers */

#include <iostream> // needed for input and output
using namespace std;

int main(){
    int userinput; //Holds the userinput to find the hailstone
    int counter = 0; // Holds the interation
    const int MOD = 2; // Holds the modulous number used to figure out if number is even or odd

    cout << "Please enter a positive integer:" << endl;
    cin >> userinput;

    while (userinput <= 0){
        cout << "The number must be a positive integer:\n";
        cin >> userinput;
        cout << endl;
    }

    cout << "Here is the series for " << userinput << endl;

    while (userinput != 1){
        //If the number passes this test case, then it is even
        if ((userinput % MOD) == 0){
            userinput = userinput / 2;
            counter++;
        }

        //If it is odd, then follows the rules for odd numbers in Hailstone series
        else{
            userinput *= 3;
            userinput++;
            counter++;
        }

        cout << userinput << " ";

        }
    cout << endl;
    cout << "The number of iterations was " << counter << endl;

    return (0);
}
