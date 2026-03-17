#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>


//TODO указать в название метода что она реверсит
//TODO переводить число не в строку, реверсить число нужно сдвигами
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

    //TODO также поработать с названием функции, высчитывать степень
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

int main(int argc, char* argv[])
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    if (argc != 2) {
        std::cout << "ERROR: Неправильный формат. Используйте: flipbyte.exe <число от 0 до 255>" << std::endl;
        return 1;
    }

    std::string arg = argv[1];
    for (char c : arg) {
        if (!isdigit(c)) {
            std::cout << "ERROR: Введите корректное число!" << std::endl;
            return 1;
        }
    }

    //TODO какие исключение может давать atoi
	int EnterNumber = std::atoi(argv[1]);;
    
    //TODO тесты границ
    if (EnterNumber >= 0 && EnterNumber <= 256)
    {
        std::string Binary = BinaryNumber(EnterNumber);
    
        int Decimal = FinalNumber(Binary);
        std::cout << Decimal;
    } 
    else 
    {
        std::cout << "ERROR: число должно быть в диапозоне от 0 до 255!!! \n";
    }

}