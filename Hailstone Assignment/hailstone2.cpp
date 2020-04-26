/* This program was made by Samin Q on
Feburary 4th. This program is an implemantation
of Hailstone Numbers */

#include <iostream> // needed for input and output
using namespace std;

int main(){
    int largest = 0;
    int largest_iteration = 0;
    int counter = 0;
    const int MOD = 2;
    int temp;
    int userinput;

   for (int i = 1; i <= 200; i++){
        userinput = i;
        counter = 0;
        while(userinput != 1){
            if ((userinput % MOD) == 0){
                userinput = userinput / 2;
            }

            else{
                userinput *= 3;
                userinput++;
            }
            counter++;
            if (largest_iteration < counter){
                largest_iteration = counter;
                largest = i;
            }
        }

        cout << "The number of iterations for " << i << " is " << counter;
        cout << endl;
   }
    cout << endl;
    cout << "The number with the largest iterations is "<< largest << "with " << largest_iteration << "iterations";

    return (0);
}
