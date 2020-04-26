/* This program was made by Samin Q on
Feburary 4th. This program is an implemantation
of Hailstone Numbers */

#include <iostream> // needed for input and output
using namespace std;

int main(){
    int userinput;
    int counter = 0;
    const int MOD = 2;

    cout << "Please enter a positive integer:" << endl;
    cin >> userinput;

    while (userinput <= 0){
        cout << "The number must be a positive integer:\n";
        cin >> userinput;
        cout << endl;
    }

    cout << "Here is the series for " << userinput << endl;

    do{
        if ((userinput % MOD) == 0){
            userinput = userinput / 2;
            counter++;
        }

        else{
            userinput *= 3;
            userinput++;
            counter++;
        }
        cout << userinput << " ";
        }while (userinput != 1);
    cout << endl;
    cout << "The number of iterations was " << counter << endl;

    return (0);
}
