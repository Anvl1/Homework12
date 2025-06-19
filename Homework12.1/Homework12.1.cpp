#include <iostream>
#include <fstream>
#include <string>
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

    std::string word;
    while (inputFile >> word)
    {
        std::cout << word << std::endl;
    }

    inputFile.close();
    return 0;
}