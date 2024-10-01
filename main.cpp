#include <iostream>
#include <string>
#include "kedelkloppersprook.h"

int main() {
    std::string text;
    std::cout << "Zu uebersetzender Text: \n";
    std::getline(std::cin, text);
    text = toKedelkloppersprook(text);
    std::cout << "\n" << text;
}
