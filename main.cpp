#include <iostream>
#include <string>
#include "kedelkloppersprook.h"

//Zeilen zum testen
//Wann mol iuwer ne dumme Sake Gras wassen is, dann kiemmet ganz sieker en Kameil un frietert wie af.

int main() {
    std::string text;
    std::cout << "Zu uebersetzender Text: \n";
    std::getline(std::cin, text);
    text = toKedelkloppersprook(text);
    std::cout << "\n" << text;
}
