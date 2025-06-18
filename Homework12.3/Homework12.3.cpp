#include <iostream>
#include <fstream>
#include <Windows.h>

int main()
{
    int size;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::ofstream outFile("out.txt");
    if (!outFile)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        delete[] arr;
        return 1;
    }

    outFile << size << std::endl;

    for (int i = size - 1; i >= 0; --i)
    {
        outFile << arr[i] << (i == 0 ? "" : " ");
    }

    outFile.close();

    delete[] arr;

    return 0;
}
