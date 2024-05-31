/** @file morseCodeFunctions.h
  * @brief Plik nagłówkowy do przechowywania definicji funkcji, struktur oraz klas do obsługi kodu Morse'a oraz tekstu.
  */

#ifndef MORSE_CODE_H
#define MORSE_CODE_H
#include <string>

using namespace std;

    /**
     * @brief Pola przechowujące znak i odpwiedni kod Morse'a.
     *
     * Klasa przechowująca dwa pola potrzebne do stworznia bazy kodu.
     * Jedno pole 'character' dla znaku oraz drugie pole dla odpwiedniemu kodzie Morse'a 'code'.
     * Konstruktor jest używany do stworzenia elemetów tablicy jednowymiarowej.
     * W parametrach konstruckotra można przekazać znak oraz odpowiedni kod Morse'a.
     * Te dane będą zapamietywane w nowych obiektach klasy.
     */
class MorseCodeComponents
{
    public:
        /// Znak.
        char character;
        /// Kod Morse'a.
        string code;

        MorseCodeComponents(char parm_character, string parm_code)
        {
            character = parm_character;
            code = parm_code;
        }
};
//-----------------------------------------------------------------------------------

    /**
      * @brief Elementy Kodu Morse'a.
      *
      * Struktura danych zawierająca elementy jednokierunkowej listy dynamicznej
      * do przechowywania kodu Morse'a danego znaku w formie 'string' oraz wzkaznik do nastepnego elementu.
      *
      */
struct morseCodeElement
{
    string code;
    morseCodeElement * next;
};
//-----------------------------------------------------------------------------------

    /**
     * @brief Pojedyncze znaki tekstu
     *
     * Struktura danych zawierająca elementy jednokierunkowej listy dynamicznej
     * do przechowywania danego znaku w formie 'char' oraz wzkaznik do nastepnego elementu.
     */
struct textElement
{
    char character;
    textElement * next;
};
//-----------------------------------------------------------------------------------

    /**
      * @brief Klasa przechowująca objekty oraz funkcje związane z przetwarzaniem kodu Morse'a oraz tekstu.
      *
      * Klasa przechowująca objekty oraz funkcje związane z przetwarzaniem danych
      * wejściowych czyli tekstu albo kodu Morse'a i możliwość wyświetlenia resultatu po przetworzeniu.
      */
class MorseCodeFunctions{
public:
        /// Rozmiar tablicy jednokierunkwej przechowującej obiekty klasy 'MorseCodeComponents'.
    static const int NUMBER_OF_COMPONENTS = 41;
        /**
         * @brief Konstruktor klasy.
         */
    MorseCodeFunctions(){};
        /**
         * @brief Baza danych przechowująca znaki oraz odpowiedni kod Morse'a.
         *
         * Funkcja tworząca tablice jednowymiarową typu klasy 'MorseCodeComponents', gdzie zwracany jest element 'i'.
         * @param i- Element tablicy który funkcja ma zwracać.
         * @return
         */
    MorseCodeComponents * morseCodeStorage(int i);
        /**
         * @brief Funkcja szukająca błedu w danych wejściowych.
         *
         * Funkcja sprawdzająca czy wpisany teskt albo kod Morse'a jest wpisany prawidłowo.
         * @param line- Dane wejsciowe wzięte z pliku albo wpisane przez użytkownika.
         * @param checkTextOrMorseCode- Parametr który mówi funkcji czy ma sprawdzać tekst czy kod Morse'a.
         * @return Funkcja zwraca 'true' jeśli jest bład w danych wejściowych albo 'false' jęsli nie ma błedu.
         */
    bool checkLineForError(string line, string checkTextOrMorseCode);
        /**
         * @brief Funkcja przetwarzająca Kod Morse'a danego znaku w znak.
         * @param code- Kod Morse'a znaku który będzie przetwarzany w znak.
         * @return Funckja zwraca znak danego kodu Morse'a.
         */
    char convertMorseCodeToCharacter(string code);
        /**
         * @brief Funkcja przetwarzająca znak w kod Morse'a.
         * @param character- Znak do przetworzenia w kod Morse'a.
         * @return Funkcja zwraca kod Morse'a znaku.
         */
    string convertCharacterToMorseCode(char character);
        /**
         * @brief Funkcja do tworzenia listy dynamicznej jednokierunkowej przechowującej znaki całego tekstu.
         *
         * Funkcja bierze cały kod Morse'a i przetwarza go w tekstu, każdy znak tekstu jest traktowany
         * jako nowy elementy listy dynamicznej jednokierunkowej.
         *
         * @param morseCode- Cały kod Morse'a wzięty z pliku albo wpisany przez użytkownika.
         * @return Funkcja zwraca pierwszy element czyli 'head' listy jednokierunkowej.
         */
    textElement * createListText(string morseCode);
        /**
         * @brief Funkcja do tworzenia listy dynamicznej jednokierunkowej przechowującej kod Morse'a pojedynczych znaków.
         *
         * Funkcja bierze cały tekst i przetwarza go kod Morse'a, każdy kod Morse'a znaku jest traktowany
         * jako nowy elementy listy dynamicznej jednokierunkowej.
         *
         * @param text- Cały tekst wzięty z pliku albo wpisany przez użytkownika.
         * @return Funkcja zwraca pierwszy element czyli 'head' listy jednokierunkowej.
         */
    morseCodeElement * createListMorseCode(string text);
        /**
         * @brief Funkcja do wyświetlania listy jednokierunkowej dynamicznej przechowującej tekst.
         * @param current- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         */
    void printTextList(textElement * current);
        /**
         * @brief Funkcja do wyświetlania listy jednokierunkowej dynamicznej przechowującej kod Morse'a.
         * @param current- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         */
    void printMorseCodeList(morseCodeElement * current);
        /**
         * @brief Funkcja usuwającą liste jednokierunkową przechowującą tekst.
         * @param currentElement- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         */
    void deleteTextList(textElement *& currentElement);
        /**
         * @brief Funkcja usuwającą liste jednokierunkową przechowującą kod Morse'a.
         * @param currentElement- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         */
    void deleteMorseCodeList(morseCodeElement *& currentElement);
        /**
         * @brief Funkcja do wyświetlania zawartośći tablicy jednowymiarowej przechowującej baze kodu Morse'a i znaków.
         */
    void printMorseCodeAlphabet();
        /**
         * @brief Funkcja która przetwarza tekst w kod Morse'a.
         *
         * Funkcja prosi użytkowika o wpisanie tekstu, sprawdza czy dane wejsciowe są poprawne a potem wyświetla
         * kod Morse'a.
         * @return Funkcja zwraca pierwszy element czyli 'head' listy jednokierunkowej zawierającej kod Morse'a.
         * Będzie to potrzebne w przypadku zapisania danych do pliku.
         */
    morseCodeElement * printMorseCodeFromText();
        /**
         * @brief Funkcja która przetwarza kod Morse'a w teskt.
         *
         * Funkcja prosi użytkowika o wpisanie Kodu Morse'a, sprawdza czy dane wejsciowe są poprawne a potem wyświetla
         * tekst.
         * @return Funkcja zwraca pierwszy element czyli 'head' listy jednokierunkowej zawierającej teskt.
         * Będzie to potrzebne w przypadku zapisania danych do pliku.
         */
    textElement * printTextFromMorseCode();
};

#endif // MORSE_CODE_H
