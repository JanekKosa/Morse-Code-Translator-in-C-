#include <iostream>
#include <menuWindow.h>
#include <fileFunctions.h>
#include <globalFunctions.h>

using namespace std;

void dekoder(){

    int decision;
    textElement * headAddressOfTextList = NULL;
    MorseCodeFunctions * morseCodeFunctions =  new MorseCodeFunctions();
    FileFunctions * fileFunctions =  new FileFunctions();

    cout << " Wybierz opcje:\n";
    cout << "   1) Odczyt Kodu Morse'a z pliku\n";
    cout << "   2) Samodzielne wpisanie Kodu Morse'a\n";
    cout << "   3) RETURN\n";
    cout << " > ";
    cin >> decision;
    if(decision == 1){
        clearScreen();
        fileFunctions->useInputFromFile("morseCode");
    }
    else if(decision == 2){
        clearScreen();
        headAddressOfTextList = morseCodeFunctions->printTextFromMorseCode();
        cout << "\n\n\n Wybierz opcje:\n";
        cout << "   1) Zapisz Kod Morse'a do pliku\n";
        cout << "   2) RETURN\n";
        cout << "   3) Exit\n ";
        cout << "> ";
        cin  >> decision;
        cout << endl;
        if(decision == 1){
            clearScreen();
            fileFunctions->saveTextToFile(headAddressOfTextList, "morseCode");
        }
        else if(decision == 2){
            clearScreen();
            dekoder();
        }
        else if(decision == 3){
            morseCodeFunctions->deleteTextList(headAddressOfTextList);
            delete morseCodeFunctions;
            delete fileFunctions;
            clearScreen();
            exit(0);
        }
        morseCodeFunctions->deleteTextList(headAddressOfTextList);
    }
    else if(decision == 3){
        clearScreen();
        menu();
    }
    delete morseCodeFunctions;
    delete fileFunctions;
}
