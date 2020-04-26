
//This program was made by Samin Q on Feb 26
//A program that implents pointers and linked lists

#include <iostream>
using namespace std;

//Tells C++ our user-defined node struct
struct Node {
    string word;
    Node* next;
};

string UpperCase(string phrase) {
    /*Returns a copy of a phrase with all lowercase
    characters converted to uppercase characters. */

    //index is used to irreate through phrase
    //phrase is the user inputted palindrome
    for (int index = 0; index < phrase.length(); index++) {
        if ((phrase[index] >= 'a') && (phrase[index] <= 'z')) {
            phrase[index] = phrase[index] - 'a' + 'A';
        }
    }
    return(phrase);
}

void Display(Node *start) {
    //Displays the start list
    //current_word is the current word position
    Node* previous;
    Node* current_word = start;
    while (current_word != NULL) {
        cout << current_word->word << endl;
        previous = current_word;
        current_word = current_word->next;
        delete previous;

    }
    return;

}

void AddItem(Node*& start, Node* newentry) {
    //AddItem is adding items anywhere not in the begining
    //next_word and previous are pointers
    //runloop is a run boolean
    Node* next_word = start->next;
    Node* previous = start;
    bool runloop = true;

    while (runloop) {

        if (next_word != NULL) {

            if (UpperCase(newentry->word) > UpperCase(next_word->word)) {
                next_word = next_word->next;
                previous = previous->next;
            }

            else {
                runloop = false;
            }
        }

        else {
            runloop = false;
        }
    }

    previous->next = newentry;
    newentry->next = next_word;
    return;
}


void AddAtStart(Node *&start, Node* newentry) {
    //newenetry is the node with user entered word
    newentry->next = start;
    start = newentry;
    return;
}

Node* GetWord() {
    //Gets a word from the user
    //newentry is a new node
    Node* newentry = new Node;
    cout << "Please enter a word: ";
    cin >> newentry->word;
    newentry->next = NULL;
    cout << "\n";

    return(newentry);
}

Node* StartList(Node* newentry) {
    //Starts the linked list
    //start is a node that starts the linked list
    Node* start = newentry;
    start->next = NULL;
    return(start);
}

int main() {
    //mainline
    //start and newentry are nodes
    //start is the first node in the linked list
    //newentry is the node that holds userinput
    Node* start;
    Node* newentry;
    newentry = GetWord();


    if (UpperCase(newentry->word) != "DONE") {
        start = StartList(newentry);
        newentry = GetWord();
        while (UpperCase(newentry->word) != "DONE") {
            if (UpperCase(newentry->word) < UpperCase(start->word)) {
                AddAtStart(start, newentry);
            }
            else {
                AddItem(start, newentry);

            }
            newentry = GetWord();
        }
        Display(start);
    }
    else {
        cout << "\nGoodbye";
    }


}

