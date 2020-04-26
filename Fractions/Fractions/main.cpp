//This program was made by Samin Q on Feb 25, 2020
//This program adds up fractions


//TODO: Fix the Zero error in num (Fixed)

#include <iostream>
using namespace std;

void Reduce(int& num, int& denom) {
	/*This function reduces fractions to their simpliest form*/
	//num is the numerator of the fraction
	//denom is the denominator of the fraction
	//i is the index value to search for the gcd
	for (int i = num; i > 0; i--) {
		if (num % i == 0 && denom % i == 0) {
			num /= i;
			denom /= i;
		}
	}
	//cout << num << "/" << denom << "H2O\n";
	return;
}

void Display(int num, int denom) {
	/*This function display fractions in there proper form*/
	//num is the numerator of the fraction
	//denom is the denominator of the fraction

	if ((num == 0) || (denom == 1)) {
		cout << num;
	}

	else {
		cout << num << "/" << denom;
	}
	return;
}

void Add(int num, int denom, int num2, int denom2, int &num3, int &denom3){
	/*This function adds fractions using the butterfly method*/

	//num is the numerator of the fraction
	//denom is the denominator of the fraction
	//is_frac_neg a bool that tells the program if
	//fraction is a negative fraction
	bool is_frac_neg = false;
	num3 = (num * denom2) + (num2 * denom);
	denom3 = denom * denom2;
	if (num3 < 0) {
		num3 *= -1;
		is_frac_neg = true;
	}
	Reduce(num3, denom3);

	if (is_frac_neg) {
		num3 *= -1;
	}
	return;
}


void ReadFraction(int& num, int& denom) {
	/*This function takes fraction info from the user
	and handles special cases such as negatives and 0's*/
	//num is the numerator of the fraction
	//denom is the denominator of the fraction
	//is_frac_neg a bool that tells the program if
	//fraction is a negative fraction

	bool is_frac_neg = false;

	cout << "Please enter your numerator: ";
	cin >> num;

	cout << "Please enter your denominator: ";
	cin >> denom;

	//cout << num << "/" << denom;

	while (denom == 0) {
		cout << "0 for denominator is not allowed\n";
		cout << "Please enter a new denominator for the fraction: ";
		cin >> denom;
	}


	if (denom != 1 && denom != -1){
		if (num < 0 && denom < 0) {
			num *= -1;
			denom *= -1;
		}
		if (denom < 0) {
			is_frac_neg = true;
			denom *= -1;
		}

		if (num < 0) {
			is_frac_neg = true;
			num *= -1;
		}
		Reduce(num, denom);

		if (is_frac_neg) {
			num *= -1;
		}
	}

	if (denom == -1) {
		num *= -1;
		denom *= -1;
	}
	cout << "\n";
	return;
}


int main() {
	int num, denom, num2, denom2, num3 = 0, denom3 = 0;
	//num, num2, and num3 are the numerators of their respected fractions
	ReadFraction(num, denom);
	ReadFraction(num2, denom2);
	Add(num, denom, num2, denom2, num3, denom3);

	cout << "The sum of the fractions is: \n";
	Display(num, denom);
	cout << " + ";
	Display(num2, denom2);
	cout << " = ";
	Display(num3, denom3);

	return (0);
}
