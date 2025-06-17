#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile("in.txt");
    
    if (!inputFile)
    {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream stream(line);
        std::string word;
        while (stream >> word)
        {
            std::cout << word << std::endl;
        }
    }

    inputFile.close();
    return 0;
}