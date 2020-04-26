/* This program was made by Samin Q on
Feburary 4th. This program is an implemantation
of Hailstone Numbers. It finds the number with
the largest iteration in a range from 1 to 200*/

#include <iostream> // needed for input and output
using namespace std;

int main(){
    int largest = 0; //Largest holds the number with the largest iterations
    int largest_iteration = 0; //largest_iteration is the accompnying variable that holds the largest interation
    int counter = 0; //Variable that holds the iteration
    const int MOD = 2; //Constant that holds the modulous number to check if it is even or odd
    int currentnum; //Holds the current number checking to see if it is the number with largest iteration

   for (int i = 1; i <= 200; i++){
        currentnum = i;
        counter = 0;

        while(currentnum != 1){
            //If the number passes this test case, then it is even
            if ((currentnum % MOD) == 0){
                currentnum = currentnum / 2;
            }

            //If it is odd, then follows the rules for odd numbers in Hailstone series
            else{
                currentnum *= 3;
                currentnum++;
            }
            counter++;

            if (largest_iteration < counter){
                largest_iteration = counter;
                largest = i;
            }
        }
   }
    cout << endl;
    cout << "The number with the largest iterations is "<< largest << " with " << largest_iteration << " iterations";
    cout << endl;

    return (0);
}
