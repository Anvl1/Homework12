#include <iostream>
#include <fstream>
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

    int size;
    inputFile >> size;
    if (size <= 0)
    {
        std::cerr << "Некорректный размер массива!" << std::endl;
        return 1;
    }

    int* array = new int[size];
    
    for (int i = 0; i < size; ++i)
    {
        inputFile >> array[i];
    }

    inputFile.close();
    
    for (int i = size - 1; i >= 0; --i)
    {
        std::cout << array[i];
        if (i != 0)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    delete[] array;
    
    return 0;
}