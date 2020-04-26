/*Made by Samin Q on Feb 10th 2020
This program tells the user if the input
they give is a palindrome*/

#include <iostream>
using namespace std;

string UpperCase(string phrase){
    /*Returns a copy of a phrase with all lowercase
    characters converted to uppercase characters. */

    //index is used to irreate through phrase
    //phrase is the user inputted palindrome
    for (int index = 0; index < phrase.length(); index++){
        if ((phrase[index] >= 'a') && (phrase[index] <= 'z')){
            phrase[index] = phrase[index] - 'a' + 'A';
        }
    }
    return(phrase);
};

string Reverse(string palindrome){
    /*Reverse function takes any
    given userinput, and returns
    the reverse of it*/
    //refer to sorting algo

    //endpos is the position of the last char that has not been switched
    //temp is a temp variable that is built for the reverse of the string

    int endpos = palindrome.length()-1;

    string temp = "";

    for(int i=endpos; i >=0;i--){

        temp += palindrome[i];
      }

        return (temp);
}

string JustLetters(string palindrome){
    /*Accepts any user given string
    remove any character not a letter*/
    //temp_word_var is a temp variable that would hold the letters from the userinput

    string temp_word_var = "";
    int strlen = palindrome.length();
    for(int i= 0; i <= strlen; i++){
         if ((palindrome[i] >= 'A') && (palindrome[i] <= 'Z') || ((palindrome[i] >= 'a') && (palindrome[i] <= 'z'))){
            temp_word_var += palindrome[i];
        }
    }

    return(temp_word_var);

}

bool IsPalin(string palindrome){
    /*Checks to see if the word is a palindrome*/
    //palindrome_cc is a carbon copy of palindrome
    //that is manipulated to check to see if the word
    // is a palindrome
    string palindrome_cc = Reverse(UpperCase(JustLetters(palindrome)));
    palindrome = UpperCase(JustLetters(palindrome));

    if (palindrome == palindrome_cc){
        return (true);
    }
    else{
        return (false);
    }
}

int main(){
    //palindrome is the userinput that is used to check
    string palindrome = "";
    cout << "This program tells you that if your input is a palindrome\n";
    cout << "Enter a word, enter \"done\" to finish: ";
    getline(cin, palindrome);

    while(UpperCase(palindrome) != "DONE"){

        if (IsPalin(palindrome) == true){
            cout << palindrome << " is a Palindrome\n";
        }
        else{
            cout << palindrome << " is notk a palindrome\n";
        }

        cout << "Enter a word, enter \"done\" to finish: ";
        getline(cin, palindrome);


    };
    return (0);
}


