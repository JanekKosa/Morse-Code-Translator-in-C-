/** @file fileFunctions.h
 *  @brief Plik nagłówkowy modułu klasy 'fileFunctions'.
 *
 *  Klasa zawierająca definicje klasy 'fileFunctions' i jej funkcje.
 */

#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H
#include <morseCodeFunctions.h>

    /**
     * @brief Definicja klasy zawierącej funkcje składowe związne z operacją nad plikami.
     */
class FileFunctions{
private:
        /**
         * @brief Funkcja zwracająca pojedyńcze linie z pliku.
         * @param file- Adres pliku z którego chcemy pobrać linie.
         * @param lineFromFile- Numer linii którą chcemy.
         * @return Funkcja zwraca wybraną linie z pliku w formie 'string'.
         */
    string getLineFromFile(ifstream & file, int lineFromFile);
public:
        /**
         * @brief Konstruktor klasy.
         */
    FileFunctions(){};
        /**
         * @brief Funkcja zapisująca liste jednokierunkową do pliku.
         *
         * Lista jednokierunkowa dynamiczna przechowująca elementy tekstu.
         * @param current- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         * @param textOrMorseCode- Parametr informujący funkcje czy wrócic do dekodera czy do koder po wcisnięciu 'RETURN'.
         *
         */
    void saveTextToFile(textElement * current, string textOrMorseCode);
        /**
         * @brief Funkcja zapisująca liste jednokierunkową do pliku.
         *
         * Lista jednokierunkowa dynamiczna przechowująca elementy kodu Morse'a.
         * @param current- Wskaznik do pierwszego elementu listy jednokierunkowej czyli 'head'.
         * @param textOrMorseCode- Parametr informujący funkcje czy wrócic do dekodera czy do koder po wcisnięciu 'RETURN'.
         *
         */
    void saveMorseCodeToFile(morseCodeElement * current, string textOrMorseCode);
        /**
         * @brief Funkcja przetwarzająca teskt albo kod Morse'a wzięte z pliku.
         *
         * Funckja przetwarzająca tekst z pliku w kod Morse'a oraz kod Morse'a z pliku w tekst.
         * @param textOrMorseCode- Parametr informujący funkcje czy przetworzyć tekst czy kod Morse'a.
         */
    void useInputFromFile(string textOrMorseCode);
};

#endif // FILEFUNCTIONS_H
