#include <iostream>
#include <string>

void replaceSpaces(std::string& str, int trueLength) {
    int spaceCount = 0;
    for (int i = 0; i < trueLength; ++i) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }

    int newIndex = trueLength + spaceCount * 2;
    for (int i = trueLength - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            str[newIndex - 1] = '0';
            str[newIndex - 2] = '2';
            str[newIndex - 3] = '%';
            newIndex -= 3;
        } else {
            str[newIndex - 1] = str[i];
            newIndex--;
        }
    }
}

int main() {
    std::string input = "my name is vishal            ";
    int trueLength = 20; // Length of "my name is vishal"
    replaceSpaces(input, trueLength);
    
    // Print the modified string
    std::cout << "Modified String: " << input << std::endl;

    return 0;
}


