#include <iostream>
#include <string>
#include <windows.h>
#include <morseCodeFunctions.h>
#include <globalFunctions.h>
using namespace std;

MorseCodeComponents * MorseCodeFunctions::morseCodeStorage(int i){

    MorseCodeComponents * morseCodeArray[MorseCodeFunctions::NUMBER_OF_COMPONENTS] = { new MorseCodeComponents('A', ".-"),
                                                                                       new MorseCodeComponents('B', "-..."),
                                                                                       new MorseCodeComponents('C', "-.-."),
                                                                                       new MorseCodeComponents('D', "-.."),
                                                                                       new MorseCodeComponents('E', "."),
                                                                                       new MorseCodeComponents('F', "..-."),
                                                                                       new MorseCodeComponents('G', "--."),
                                                                                       new MorseCodeComponents('H', "...."),
                                                                                       new MorseCodeComponents('I', ".."),
                                                                                       new MorseCodeComponents('J', ".---"),
                                                                                       new MorseCodeComponents('K', "-.-"),
                                                                                       new MorseCodeComponents('L', ".-.."),
                                                                                       new MorseCodeComponents('M', "--"),
                                                                                       new MorseCodeComponents('N', "-."),
                                                                                       new MorseCodeComponents('O', "---"),
                                                                                       new MorseCodeComponents('P', ".--."),
                                                                                       new MorseCodeComponents('Q', "--.-"),
                                                                                       new MorseCodeComponents('R', ".-."),
                                                                                       new MorseCodeComponents('S', "..."),
                                                                                       new MorseCodeComponents('T', "-"),
                                                                                       new MorseCodeComponents('U', "..-"),
                                                                                       new MorseCodeComponents('V', "...-"),
                                                                                       new MorseCodeComponents('W', ".--"),
                                                                                       new MorseCodeComponents('X', "-..-"),
                                                                                       new MorseCodeComponents('Y', "-.--"),
                                                                                       new MorseCodeComponents('Z', "--.."),
                                                                                       new MorseCodeComponents('0', "-----"),
                                                                                       new MorseCodeComponents('1', ".----"),
                                                                                       new MorseCodeComponents('2', "..---"),
                                                                                       new MorseCodeComponents('3', "...--"),
                                                                                       new MorseCodeComponents('4', "....-"),
                                                                                       new MorseCodeComponents('5', "....."),
                                                                                       new MorseCodeComponents('6', "-...."),
                                                                                       new MorseCodeComponents('7', "--..."),
                                                                                       new MorseCodeComponents('8', "---.."),
                                                                                       new MorseCodeComponents('9', "----."),
                                                                                       new MorseCodeComponents('.', ".-.-.-"),
                                                                                       new MorseCodeComponents(',', "--..--"),
                                                                                       new MorseCodeComponents('?', "..--.."),
                                                                                       new MorseCodeComponents('!', "-.-.--"),
                                                                                       new MorseCodeComponents('\'', ".----.")
                                                                                       };
        return morseCodeArray[i];
    }
//----------------------------------------------------------------------------------------------------------------------------------------
bool MorseCodeFunctions::checkLineForError(string line, string checkTextOrMorseCode){

    int lineSize = line.size();

    if(checkTextOrMorseCode == "morseCode"){
        bool error;
        int startOfMorseCode = 0, lengthOfMorseCode;
        string morseCodeOfChar;


        if(!(line.find('/')!=string::npos)){
            return true;
        }

        for(int i=0; i<lineSize; i++){
            if(!(line[i] == '/') && !(line[i] == '.') && !(line[i] == '-') && !isspace(line.at(i)) ){
                return true;
            }
            if(line[i] == '/'){
                lengthOfMorseCode = i-startOfMorseCode;
                morseCodeOfChar = line.substr(startOfMorseCode, lengthOfMorseCode);
                startOfMorseCode = i+1;
                error = true;

                for(int j=0; j<MorseCodeFunctions::NUMBER_OF_COMPONENTS; j++){
                    if(morseCodeOfChar == morseCodeStorage(j)->code){
                       error = false;
                    }
                }
                if(error == true){
                    return true;
                }
             }
            else if(isspace(line.at(i))){
                startOfMorseCode = i+1;
            }
        }
    }
    //--------------------------------------------------------------------------------------------------------------------
    else if(checkTextOrMorseCode == "text"){
        for(int i=0; i<lineSize; i++)
        {
            if(!((line[i]>='A' && line[i]<='Z') || (line[i]>='a' && line[i]<='z') || line[i]=='?' || line[i]==',' || line[i]=='.' || line[i]=='!' || line[i]=='\'' || isdigit(line[i]) || isspace(line.at(i))))
            {
                return true;
            }
        }
    }
    return false;
}
//---------------------------------------------------------------------------------------------------------------------------------
char MorseCodeFunctions::convertMorseCodeToCharacter(string code){

    char character;

    for(int i=0; i<MorseCodeFunctions::NUMBER_OF_COMPONENTS; i++)
    {
        if(code == morseCodeStorage(i)->code)
        {
            character = morseCodeStorage(i)->character;
        }
    }
   return character;
}
//----------------------------------------------------------------------------------------------------------------------------------
string MorseCodeFunctions::convertCharacterToMorseCode(char character){

    string code;

    for(int i=0; i<MorseCodeFunctions::NUMBER_OF_COMPONENTS; i++)
    {
        character = toupper(character);
        if(character == morseCodeStorage(i)->character)
        {
            code = morseCodeStorage(i)->code;
        }
    }
   return code ;
}
//---------------------------------------------------------------------------------------------------------------------------------
textElement * MorseCodeFunctions::createListText(string morseCode){

    int morseCodeSize = morseCode.size(), startOfMorseCode = 0 , lengthOfMorseCode;
    string morseCodeOfChar;
    textElement * head = NULL;
    textElement * tail = NULL;

    for(int i=0; i<morseCodeSize; i++){

        if(morseCode[i]=='\n'){
            textElement * newElement = new textElement;

            newElement->character = '\n';
            newElement->next = NULL;
            if(head == NULL){
                head = newElement;
                tail = newElement;
            }
            else{
                tail->next = newElement;
                tail = newElement;
            }
            startOfMorseCode=i+1;
            continue;
        }

        if(morseCode[i] == '/'){
            textElement * newElement = new textElement;
            lengthOfMorseCode = i-startOfMorseCode;
            morseCodeOfChar = morseCode.substr(startOfMorseCode, lengthOfMorseCode);
            startOfMorseCode = i+1;

            newElement->character = convertMorseCodeToCharacter(morseCodeOfChar);
            newElement->next = NULL;
            if(head == NULL){
                head = newElement;
                tail = newElement;
            }
            else{
                tail->next = newElement;
                tail = newElement;
            }
        }
        else if(isspace(morseCode.at(i))){
            textElement * newElement = new textElement;
            newElement->character = ' ';
            newElement->next = NULL;
            if(head == NULL){
                head = newElement;
                tail = newElement;
            }
            else{
                tail->next = newElement;
                tail = newElement;
            }
            startOfMorseCode = i+1;
        }
    }
    return head;
}
//-------------------------------------------------------------------------------------------------------------------------------------
morseCodeElement * MorseCodeFunctions::createListMorseCode(string text){

    int textSize = text.size();
    morseCodeElement * head = NULL;
    morseCodeElement * tail = NULL;

    for(int i=0; i<textSize; i++)
    {
        if(text[i]=='\n'){
            morseCodeElement * newElement = new morseCodeElement;
            newElement->code =  '\n';
            newElement->next = NULL;
            if(head == NULL)
            {
                head = newElement;
            }
            else
            {
                tail->next = newElement;
            }
            tail = newElement;
            continue;

        }

        if(!isspace(text.at(i)))
        {
            morseCodeElement * newElement = new morseCodeElement;
            newElement->code =  convertCharacterToMorseCode(text[i]) + "/";
            newElement->next = NULL;
            if(head == NULL)
            {
                head = newElement;
            }
            else
            {
                tail->next = newElement;
            }
            tail = newElement;
        }
        else if(isspace(text.at(i)))
        {
            morseCodeElement * newElement = new morseCodeElement;
            newElement->code = " ";
            newElement->next = NULL;
            if(head == NULL)
            {
                head = newElement;
                tail = newElement;
            }
            else
            {
                tail->next = newElement;
                tail = newElement;
            }
        }
    }
    return head;
}
//----------------------------------------------------------------------------------------------------------------------------------
void MorseCodeFunctions::printTextList(textElement * current){

    cout << " ";
    while(current != NULL){
        cout << current->character;
        current = current->next;
    }
}
//--------------------------------------------------------------------------------------------------------------------------
void MorseCodeFunctions::printMorseCodeList(morseCodeElement * current){

    cout << " ";
    while(current != NULL){
        cout << current->code;
        current = current->next;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void MorseCodeFunctions::deleteTextList(textElement *& currentElement){

    while(currentElement != NULL){
        textElement * previousElement = currentElement;
        currentElement = currentElement->next;
        delete previousElement;
    }
}
//---------------------------------------------------------------------------------------------------------------------------
void MorseCodeFunctions::deleteMorseCodeList(morseCodeElement *& currentElement){

    while(currentElement != NULL){
        morseCodeElement * previousElement = currentElement;
        currentElement = currentElement->next;
        delete previousElement;
    }
}
//-------------------------------------------------------------------------------------------------------------------------
void MorseCodeFunctions::printMorseCodeAlphabet(){

    for(int i=0; i<MorseCodeFunctions::NUMBER_OF_COMPONENTS; i=i+4){
        cout << " ";
        cout << morseCodeStorage(i)->character << " = " << morseCodeStorage(i)->code << "       ";

        if(i+1<MorseCodeFunctions::NUMBER_OF_COMPONENTS){
            cout << morseCodeStorage(i+1)->character << " = " << morseCodeStorage(i+1)->code << "       ";
        }
        if(i+2<MorseCodeFunctions::NUMBER_OF_COMPONENTS){
            cout << morseCodeStorage(i+2)->character << " = " << morseCodeStorage(i+2)->code << "       ";
        }
        if(i+3<MorseCodeFunctions::NUMBER_OF_COMPONENTS){
            cout << morseCodeStorage(i+3)->character << " = " << morseCodeStorage(i+3)->code << "       \n";
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------
morseCodeElement * MorseCodeFunctions::printMorseCodeFromText(){

    string text;
    int count = 0;

    do{
        clearScreen();
        if(count != 0)
        {
            cout << " !!  ERROR :: Wprowadziles niedozwolony znak/znaki  !!\n";
            cout << " !!  Sprobuj ponownie  !!\n";
            cout << endl;
        }
        cout << " Dozwolone znaki: (Litery angielskie)  (numery)  (spacja)  (.)  (,)  (?) (!) (')\n";
        cout << " Wypisz tekst: \n\n";
        cout << " ";
        if(count == 0){
            cin.ignore();
        }
        getline(cin, text);
        count++;
    }
    while(checkLineForError(text, "text") == true);
    cout << endl;
    morseCodeElement * headListMorseCodeFromText = NULL;
    headListMorseCodeFromText = createListMorseCode(text);
    printMorseCodeList(headListMorseCodeFromText);

    return headListMorseCodeFromText;

}
//-------------------------------------------------------------------------------------------------------------------------
textElement * MorseCodeFunctions::printTextFromMorseCode(){

    string morseCode;
    int count = 0;

    do
    {
        clearScreen();
        if(count != 0)
        {
            cout << " !!  ERROR :: Wprowadziles niedozwolony znak/znaki  !!\n";
            cout << " !!  Sprobuj ponownie  !!\n";
            cout << endl;
        }
        printMorseCodeAlphabet();
        cout << endl << endl;
        cout << " Instrukcja- Wpisz kod Morse'a danego znaku, zakanczajac kazdy pojedynczy znak znakiem (/).\n";
        cout << "             Odziel pojedyncze slowa spacja.\n\n";
        cout << " Przyklad- HELLO WORLD > ...././.-../.-../---/ .--/---/.-./.-../-../\n";
        cout << "                          H   E   L    L   O    W   O   R    L   D\n\n";
        cout << " Dozwolone znaki: (spacja)  (/)  (.)  (-) \n";
        cout << " Wpisz kod Morse'a: \n\n";
        cout << " ";
        if(count == 0){
            cin.ignore();
        }
        getline(cin, morseCode);
        count ++;
    }while(checkLineForError(morseCode, "morseCode") == true);
    cout << endl;
    textElement * headListTextFromMorseCode = NULL;
    headListTextFromMorseCode = createListText(morseCode);
    printTextList(headListTextFromMorseCode);

    return headListTextFromMorseCode;

}
//------------------------------------------------------------------------------------------------------------------------------



























