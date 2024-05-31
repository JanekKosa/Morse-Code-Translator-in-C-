#include <iostream>
#include <fstream>
#include <string>
#include <morseCodeFunctions.h>
#include <fileFunctions.h>
#include <globalFunctions.h>
#include <koderWindow.h>
#include <dekoderWindow.h>

using namespace std;


string FileFunctions::getLineFromFile(ifstream & file, int lineFromFile){

    string currentLine;
    int i = 1;
    file.seekg(0);
    while(getline(file, currentLine)){
        if (i == lineFromFile){
            if(currentLine.empty()){
                cout << " !!  ERROR:: Wprowadzona linia numer [" << i << "] jest pusta  !!\n";
                return "";
            }
            return currentLine;
        }
        i++;
    }
    cout << " !!  ERROR:: Brak linii numer [" << i << "]  !!\n";
    return "";
}
//--------------------------------------------------------------------------------------------------
void FileFunctions::saveTextToFile(textElement * current, string textOrMorseCode){

    ofstream file;
    string fileName;
    int decision;

    cout << " Wpisz nazwe pliku: ";
    cin >> fileName;
    cout << endl;
    file.open(fileName, ios::app);

    while(current != NULL){
        file << current->character;
        current = current->next;
    }
    file << '\n';
    file.close();
    cout << " Tekst zostal zapisny do pliku < " << fileName + " >\n\n";
    cout << " 1) RETURN\n";
    cout << " 2) Exit\n";
    cout << " > ";
    cin  >> decision;
    if(decision == 1){
        clearScreen();
        if(textOrMorseCode == "text"){
            koder();
        }
        else if(textOrMorseCode == "morseCode"){
            dekoder();
        }
    }
    else if(decision == 2){
        clearScreen();
        exit(0);
    }
}
//----------------------------------------------------------------------------------------------------------
void FileFunctions::saveMorseCodeToFile(morseCodeElement * current, string textOrMorseCode){

    ofstream file;
    string fileName;
    int decision;

    cout << " Wpisz nazwe pliku: ";
    cin >> fileName;
    cout << endl;
    file.open(fileName, ios::app);

    while(current != NULL){
        file << current->code;
        current = current->next;
    }
    file << '\n';
    file.close();
    cout << " Kod Morsa zostal zapisny do pliku < " << fileName + " >\n\n";
    cout << " 1) RETURN\n";
    cout << " 2) Exit\n";
    cout << " > ";
    cin  >> decision;
    if(decision == 1){
        clearScreen();
        if(textOrMorseCode == "text"){
            koder();
        }
        else if(textOrMorseCode == "morseCode"){
            dekoder();
        }
    }
    else if(decision == 2){
        clearScreen();
        exit(0);
    }
}
//--------------------------------------------------------------------------------------------------------------
void FileFunctions::useInputFromFile(string textOrMorseCode){

    string fileName, line;
    int decision, fromLine, toLine, i = 1;
    ifstream file;

    MorseCodeFunctions * morseCode = new  MorseCodeFunctions();
    morseCodeElement * headListMorseCodeFromText = NULL;
    MorseCodeFunctions * text = new  MorseCodeFunctions();
    textElement * headListTextFromMorseCode = NULL;

    cout << " Wpisz nazwe pliku: ";
    cin >> fileName;
    cout << endl;
    file.open(fileName);
    if(!file.good()){
        file.close();
        cout << " !!  ERROR :: Plik nie istnieje  !!\n\n";
        cout << endl;
        cout << " 1) RETURN\n";
        cout << " 2) Exit\n";
        cout << " > ";
        cin  >> decision;
        if(decision == 1){
            clearScreen();
            if(textOrMorseCode == "text"){
                koder();
            }
            else if(textOrMorseCode == "morseCode"){
                dekoder();
            }
        }
        else if(decision == 2){
            clearScreen();
            delete morseCode;
            delete text;
            exit(0);
        }
    }
    if((file.peek() == ifstream::traits_type::eof())){
        file.close();
        cout << " !!  ERROR :: Plik jest pusty  !!\n\n";
        cout << endl;
        cout << " 1) RETURN\n";
        cout << " 2) Exit\n";
        cout << " > ";
        cin  >> decision;
        if(decision == 1){
            clearScreen();
            if(textOrMorseCode == "text"){
                koder();
            }
            else if(textOrMorseCode == "morseCode"){
                dekoder();
            }
        }
        else if(decision == 2){
            clearScreen();
            delete morseCode;
            delete text;
            exit(0);
        }
    }
    cout << " Wybierz Opcje:\n";
    cout << "   1) Wczytaj caly plik\n";
    cout << "   2) Wczytaj pojedyncze linie z pliku\n";
    cout << " > ";
    cin >> decision;
    clearScreen();
    text->printMorseCodeAlphabet();
    cout << endl;
    if(textOrMorseCode == "text"){cout << " Dozwolone znaki: (Litery angielskie)  (numery)  (spacja)  (.)  (,)  (?)\n";}
    else if(textOrMorseCode == "morseCode"){cout << " Dozwolone znaki: (spacja)  (/)  (.)  (-) \n";}
    cout << endl << endl;
   //-------------------------------------------------------------------------------------------------------------------------
    if(decision == 1){ //użytkownik wybrał odczyt z całego pliku
        string allLines = "";
        while(getline(file, line)){
            allLines = allLines + '\n' + line;
        }
        if(textOrMorseCode == "text"){
            if(morseCode->checkLineForError(allLines, textOrMorseCode) == true){
                file.close();
                cout << "\n !!  ERROR :: Wykryty niedozwlony znak/znaki w linii w pliku < " << fileName << " >  !!\n\n";
                cout << endl;
                cout << " 1) RETURN\n";
                cout << " 2) Exit\n";
                cout << " > ";
                cin  >> decision;
                if(decision == 1){
                    clearScreen();
                    if(textOrMorseCode == "text"){
                        koder();
                    }
                    else if(textOrMorseCode == "morseCode"){
                        dekoder();
                    }
                }
                else if(decision == 2){
                    clearScreen();
                    delete morseCode;
                    delete text;
                    allLines.clear();
                    exit(0);
                }
            }
            headListMorseCodeFromText = morseCode->createListMorseCode(allLines);
            cout << " " << allLines;
            morseCode->printMorseCodeList(headListMorseCodeFromText);
            cout << "\n\n\n Wybierz opcje:\n";
            cout << "   1) Zapisz Kod Morse'a do pliku\n";
            cout << "   2) Exit \n";
            cout << " > ";
            cin  >> decision;
            if(decision == 1){
                clearScreen();
                saveMorseCodeToFile(headListMorseCodeFromText, "text");
            }
            else if(decision == 2){
                file.close();
                text->deleteMorseCodeList(headListMorseCodeFromText);
                delete morseCode;
                delete text;
                clearScreen();
                exit(0);
            }
            morseCode->deleteMorseCodeList(headListMorseCodeFromText);
            allLines.clear();
            cout << endl;
        }
        //---------------------------------------------------------------------------------------------------------------------------------------------
        else if(textOrMorseCode == "morseCode"){
            if(text->checkLineForError(allLines, textOrMorseCode) == true){
                file.close();
                cout << "\n !!  ERROR :: Wykryty niedozwlony znak/znaki w linii w pliku < " << fileName << " >  !!\n\n";
                cout << endl;
                cout << " 1) RETURN\n";
                cout << " 2) Exit\n";
                cout << " > ";
                cin  >> decision;
                if(decision == 1){
                    clearScreen();
                    if(textOrMorseCode == "text"){
                        koder();
                    }
                    else if(textOrMorseCode == "morseCode"){
                        dekoder();
                    }
                }
                else if(decision == 2){
                    clearScreen();
                    delete morseCode;
                    delete text;
                    allLines.clear();
                    exit(0);
                }
            }
            headListTextFromMorseCode = text->createListText(allLines);
            cout << " " << allLines;
            text->printTextList(headListTextFromMorseCode);
            cout << "\n\n\n Wybierz opcje:\n";
            cout << "   1) Zapisz tekst do pliku\n";
            cout << "   2) Exit \n";
            cout << " > ";
            cin  >> decision;
            if(decision == 1){
                clearScreen();
                saveTextToFile(headListTextFromMorseCode, "morseCode");
            }
            else if(decision == 2){
                file.close();
                text->deleteTextList(headListTextFromMorseCode);
                delete morseCode;
                delete text;
                clearScreen();
                exit(0);
            }
            text->deleteTextList(headListTextFromMorseCode);
            allLines.clear();
        }
        i++;
}
   //-----------------------------------------------------------------------------------------------------------------------------------------
    else if(decision == 2){//użytkownik wybrał odczyt z pojedyńczych linii
        cout << " Wpisz ktore linie z pliku chcesz odczytac: \n";
        cout << "   Od linii > ";
        cin >> fromLine;
        cout << "   Do linii > ";
        cin >> toLine;
        cout << endl;
        string allLines = "";
        for(i=fromLine; i<=toLine; i++){
            line = getLineFromFile(file, i);
            if(line == ""){
                exit(0);
            }
            allLines = allLines + '\n' + line;
        }
        if(textOrMorseCode == "text"){
            if(morseCode->checkLineForError(allLines, textOrMorseCode) == true){
               file.close();
               cout << "\n !!  ERROR :: Wykryty niedozwlony znak/znaki w linii w pliku < " << fileName << " >  !!\n\n";
               cout << endl;
               cout << " 1) RETURN\n";
               cout << " 2) Exit\n";
               cout << " > ";
               cin  >> decision;
               if(decision == 1){
                   clearScreen();
                   if(textOrMorseCode == "text"){
                       koder();
                   }
                   else if(textOrMorseCode == "morseCode"){
                       dekoder();
                   }
               }
               else if(decision == 2){
                   clearScreen();
                   delete morseCode;
                   delete text;
                   allLines.clear();
                   exit(0);
               }
            }
            headListMorseCodeFromText = morseCode->createListMorseCode(allLines);
            cout << " " << allLines;
            morseCode->printMorseCodeList(headListMorseCodeFromText);
            cout << "\n\n\n Wybierz opcje:\n";
            cout << "   1) Zapisz Kod Morse'a do pliku\n";
            cout << "   2) Exit \n";
            cout << " > ";
            cin  >> decision;
            if(decision == 1){
                clearScreen();
                saveMorseCodeToFile(headListMorseCodeFromText, "text");
            }
            else if(decision == 2){
                file.close();
                text->deleteMorseCodeList(headListMorseCodeFromText);
                delete morseCode;
                delete text;
                clearScreen();
                exit(0);
            }
            morseCode->deleteMorseCodeList(headListMorseCodeFromText);
            allLines.clear();
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------
        else if(textOrMorseCode == "morseCode"){
            if(text->checkLineForError(allLines, textOrMorseCode) == true){
                file.close();
                cout << "\n !!  ERROR :: Wykryty niedozwlony znak/znaki w linii w pliku < " << fileName << " >  !!\n\n";
                cout << endl;
                cout << " 1) RETURN\n";
                cout << " 2) Exit\n";
                cout << " > ";
                cin  >> decision;
                if(decision == 1){
                    clearScreen();
                    if(textOrMorseCode == "text"){
                        koder();
                    }
                    else if(textOrMorseCode == "morseCode"){
                        dekoder();
                    }
                }
                else if(decision == 2){
                    clearScreen();
                    delete morseCode;
                    delete text;
                    allLines.clear();
                    exit(0);
                }
            }
            headListTextFromMorseCode = text->createListText(allLines);
            cout << " " << allLines;
            text->printTextList(headListTextFromMorseCode);
            cout << "\n\n\n Wybierz opcje:\n";
            cout << "   1) Zapisz tekst do pliku\n";
            cout << "   2) Exit \n";
            cout << " > ";
            cin  >> decision;
            if(decision == 1){
                clearScreen();
                saveTextToFile(headListTextFromMorseCode, "morseCode");
            }
            else if(decision == 2){
                file.close();
                text->deleteTextList(headListTextFromMorseCode);
                delete morseCode;
                delete text;
                clearScreen();
                exit(0);
            }
            text->deleteTextList(headListTextFromMorseCode);
            allLines.clear();
        }
    }

    file.close();
    delete morseCode;
    delete text;
    cout << endl;
}











