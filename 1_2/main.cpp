#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

std::string BinaryNumber(int EnterNumber)
    {
        std::string Binary;
        int Bufer;
        int Temp = EnterNumber;
        for (int i = 0; i < 8; i++) 
        {
            Bufer = Temp % 2;
            if (Bufer > 0) 
            {
            Binary = Binary + "1";
            }
            else
            {
                Binary = Binary + "0";
            }
            Temp = Temp / 2;
        }
        return Binary;
    }

    int FinalNumber(const std::string& Binary)
    {
        int Result = 0;
        int Degree = 7;

        for (char c : Binary)
        {
            if (c == '1')
            {
                Result = Result + pow(2, Degree);
                Degree = Degree - 1;
            }
            else
            {
                Degree = Degree - 1;
            }
        }
        return Result;
    };

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
	int EnterNumber;
    std::cout << "Введите число (0-255): ";
	std::cin >> EnterNumber;
    
    if (EnterNumber >= 0 && EnterNumber <= 256)
    {
        std::string Binary = BinaryNumber(EnterNumber);
    
        int Decimal = FinalNumber(Binary);
        std::cout << Decimal;
    } 
    else 
    {
        std::cout << "ERROR: число должно быть в диапозоне от 0 до 256!!! \n";
    }

}