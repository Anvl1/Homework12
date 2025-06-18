#include <iostream>
#include <fstream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ifstream inFile("in.txt");
    if (!inFile)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
    
    int rows, cols;
    inFile >> rows >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        array[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            inFile >> array[i][j];
        }
    }

    inFile.close();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            std::cout << array[i][j];
            if (j > 0)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}