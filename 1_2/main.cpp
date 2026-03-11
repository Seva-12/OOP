#include <iostream>
#include <string>
#include <cmath>

int main()
{
	int EnterNumber;
	std::cin >> EnterNumber;
    
    if (EnterNumber >= 0 && EnterNumber <= 256)
    {
        std::cout << EnterNumber + "\n";
    } 
    else 
    {
        std::cout << "ERROR \n";
    }
	
    std::string BinaryNumber;
    int bufer;
    int temp = EnterNumber;
    for (int i = 0; i < 8; i++) 
    {
        bufer = temp % 2;
        if (bufer > 0) 
        {
			BinaryNumber = BinaryNumber + "1";
        }
        else
        {
            BinaryNumber = BinaryNumber + "0";
        }
        temp = temp / 2;
    }
    std::cout << BinaryNumber + "\n";

    std::string str;
    int degree = 7;
    int FinalNumber = 0;

    for (char c : BinaryNumber)
    {
        if (c == '1')
        {
            FinalNumber = FinalNumber + pow(2, degree);
            degree = degree - 1;
        }
        else
        {
            degree = degree - 1;
        }
    }
    std::cout << FinalNumber;

}