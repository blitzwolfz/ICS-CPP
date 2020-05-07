//Made by Samin Q, on April 29th
//Implements Recursion to find sum of all numbers in a range
#include <iostream>
using namespace std;

int sigma(int number){
    int answer = number;

    if (number == 0){
        return answer;
    }
    
    else{
        answer = number + sigma(number - 1);
    }
}

// int sigmacheck(int number){
//      return (number*(number+1))/2;
// }



int main(){
    int usernum;
    
    cout << "Please enter a number\n";
    cin >> usernum;
    cout << "The sum of all numbers from 1 to " << usernum << " is " << sigma(usernum) << endl;
    
    //cout << sigmacheck(usernum);
    //cin >> usernum;
    
    return (0);
}