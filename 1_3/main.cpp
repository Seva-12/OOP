#include <iostream>
#include <string>



int main(int argc, char* argv[])
{
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!(std::cin >> matrix[i][j]))
            {
                std::cerr << "ERROR: введено не число!" << std::endl;
                return 1;
            }
        }
    }

    std::cout << "Матрица:" << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
    }

    return 0;
}