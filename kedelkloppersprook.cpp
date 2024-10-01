//
// Created by lars on 07.11.23.
//
#include <string>
#include <iostream>
#include "kedelkloppersprook.h"


// Funktion, um das nächste Wort in einer Zeile ab der Position pos zu extrahieren
std::string nextWord(std::string& line) {
    std::string word;

    while (true) {
        char c = line[0];
        if (isalpha(c)) {
            word += c;
            line.erase(0, 1);
        }
        else if (isspace(c)) {
            line.erase(0, 1);
            break;
        }
        else if (isdigit(c)) {
            word += c;
            line.erase(0, 1);
        }
        else if (ispunct(c)) {
            word += c;
            line.erase(0, 1);
            break;
        }
        else if (c == '\0')
            break;

        //std::cout << line << "\n" << word << "\n\n";
    }

    return word;
}




// Übersetzt ein Wort gemäß den Regeln der Keddelkloppersprook-Sprache
std::string translateWord(std::string& word) {
    // Findet die Position des ersten Vokals im Wort
    //size_t vowelPosition = word.find_first_of("aeiou");
    int vowelPosition = 0;


    //Durch das word iterieren und nach vokalen suchen
    //for (char c: word) {
    //    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    //        break;
    //    }
    //    vowelPosition++;
    //}

    vowelPosition = word.find_first_of("aeiou");

    // Wenn kein Vokal gefunden wurde oder das Wort leer ist, bleibt es unverändert
    if (vowelPosition == std::string::npos || word.empty()) {
        return word;
    }

    // Teilt das Wort in den Teil vor dem ersten Vokal und den Rest des Wortes
    std::string beforeVowel = word.substr(0, vowelPosition);
    std::string afterVowel = word.substr(vowelPosition);

    // Übersetzt das Wort, indem die Teile vertauscht und ein 'i' hinzugefügt wird
    std::string translation = afterVowel + beforeVowel + "i";

    //Satzzeichen aus wort entfernen
    int pos = 0;
    char punct = '\0';
    for (char c: translation) {
        if (ispunct(c)) {
            translation.erase(pos, 1);
            punct = c;
        }
        pos++;
    }

    //Wenn ein satzzeichen entfernt wurde dies hinten anhängen, wenn keins entfernt wurde ist punct = '\0' (NULL)
    if (punct != '\0') {
        translation += punct;
    }

    return translation;
}

std::string assembleSentence(std::string& line) {
    std::string sentence;
    std::string word;

    while (line.length() > 0) {
        word = nextWord(line);

        sentence += translateWord(word) + " ";
    }

    return sentence;
}


void toLowercase(std::string &word) {
    for (char &c : word)
    {
        c = tolower(c);
    }
}

std::string toKedelkloppersprook(std::string line) {
    toLowercase(line);
    return assembleSentence(line);
}