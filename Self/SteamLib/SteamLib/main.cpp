#include <iostream>
#include <stdlib.h>
#include <array>

using namespace std;

void title(){
    cout << R"( _____ _                       _     _ _
/  ___| |                     | |   (_) |
\ `--.| |_ ___  __ _ _ __ ___ | |    _| |__
 `--. \ __/ _ \/ _` | '_ ` _ \| |   | | '_ \
/\__/ / ||  __/ (_| | | | | | | |___| | |_) |
\____/ \__\___|\__,_|_| |_| |_\_____/_|_.__/ )"<< endl;
}


void menu(){

    cout << "Please choose:\n" << endl;
    cout << "1) New Account" << endl;
    cout << "2) Look-Up" << endl;
    cout << "3) Current Account" << endl;
    cout << "4) Close Account" << endl;
    cout << "5) Exit Program" << endl;
}

//array NewAcc(array alist){
//    cout << "Ok this also works" << endl;
//
//}
//
//bool LookUp(array alist, string FirstName, string LastnName, string accountnum, int pin){
//    cout << "Help this works" << endl;
//}
//
//void CurrentAcc(int pos, int pin){
//
//}
//
//array Close(array alist, string FirstName, string LastnName, string accountnum, int pin){
//
//}

int main(){
    int choose = 0;
    bool AccExist = true;
    array acclist[5][4];
    menu();
    cin >> choose;
    while (choose > 5 || choose < 1){
        cout << "Please give correct input.\n";
        menu();
    }

    while (choose != 5){
        if (choose == 1){

        }
    }


    return (0);
}






