//Made by Samin Q, on April 29th
//Implements Recursion to find GCD of two terms

#include <iostream>
using namespace std;

int gcd(int a, int b) { 
    //cout << a << b << "\n";
    //a and b are user input values, and find gcd of thm
	if (b == 0){
        return a;
    }
		 
	return gcd(b, a % b); 
} 



int main(){

    //usernum and usernum2 are user input values, and find gcd of thm
    int usernum, usernum2;

    cout << "Please enter a first number: ";
    cin >> usernum;

    cout << "Please enter another second number: ";
    cin >> usernum2;

    cout << endl;
    
    cout << "The greatest commmon divisor for " << usernum << " and " << usernum2 << " is " << gcd(usernum, usernum2) << endl;
    //cout << sigmacheck(usernum);
    cin >> usernum;
    return (0);
}