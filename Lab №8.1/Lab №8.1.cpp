#include <iostream>
#include <string>

bool containsWhile(const std::string& input) {
    std::string target = "while";

    for (size_t i = 0; i < target.length(); ++i) {
        bool found = false;
        for (size_t j = 0; j < input.length(); ++j) {
            if (target[i] == input[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

void replaceWhile(std::string& input) {
    size_t pos = input.find("while");

    while (pos != std::string::npos) {
        input.replace(pos, 5, "**");
        pos = input.find("while", pos + 2);
    }
}

int main() {
    std::string inputString;

    std::cout << "Print line: ";
    std::getline(std::cin, inputString);

    if (containsWhile(inputString)) {
        std::cout << "String contains all letters from 'while'.\n";
    }
    else {
        std::cout << "String doesn`t contain all letters with 'while'.\n";
    }

    replaceWhile(inputString);

    std::cout << "Result: " << inputString << std::endl;

    return 0;
}
