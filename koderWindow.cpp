#include <iostream>
#include <menuWindow.h>
#include <fileFunctions.h>
#include <globalFunctions.h>

using namespace std;

void koder(){

    int decision;
    MorseCodeFunctions * morseCodeFunctions =  new MorseCodeFunctions();
    FileFunctions * fileFunctions =  new FileFunctions();
    morseCodeElement * headAddressOfMorseCodeList = NULL;

    cout << " Wybierz opcje:\n";
    cout << "   1) Odczyt tekstu z pliku\n";
    cout << "   2) Samodzielne wpisanie tekstu\n";
    cout << "   3) RETURN\n";
    cout << " > ";
    cin >> decision;
    if(decision == 1){
        clearScreen();
        fileFunctions->useInputFromFile("text");
    }
    else if(decision == 2){
        clearScreen();
        headAddressOfMorseCodeList = morseCodeFunctions->printMorseCodeFromText();
        cout << "\n\n\n Wybierz opcje:\n";
        cout << "   1) Zapisz tekst do pliku\n";
        cout << "   2) RETURN\n";
        cout << "   3) Exit\n";
        cout << " > ";
        cin  >> decision;
        cout << endl;
        if(decision == 1){
            clearScreen();
            fileFunctions->saveMorseCodeToFile(headAddressOfMorseCodeList, "text");
        }
        else if(decision == 2){
            clearScreen();
            koder();
        }
        else if(decision == 3){
            morseCodeFunctions->deleteMorseCodeList(headAddressOfMorseCodeList);
            delete morseCodeFunctions;
            delete fileFunctions;
            clearScreen();
            exit(0);
        }
        morseCodeFunctions->deleteMorseCodeList(headAddressOfMorseCodeList);
    }
    else if(decision == 3){
        clearScreen();
        menu();
    }
    delete morseCodeFunctions;
    delete fileFunctions;
}


