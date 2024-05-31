#include <iostream>
#include <globalFunctions.h>
#include <koderWindow.h>
#include <dekoderWindow.h>

using namespace std;

void menu(){

    int decision;

    cout << "  =================\n";
    cout << "  | Koder Morse'a |\n";
    cout << "  =================\n\n";
    cout << " Wybierz opcje:" <<endl;
    cout << "   1) Koder Morse'a\n";
    cout << "   2) De-koder Morse'a\n";
    cout << " > ";
    cin >> decision;

    if(decision == 1){
        clearScreen();
        koder();
    }
    else if(decision == 2){
        clearScreen();
        dekoder();
    }
}


