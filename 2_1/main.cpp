#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<double> numbers;
    double num;

    std::cout << "Введите числа для массива через пробел (Enter, затем Ctrl+Z/D для конца)" << std::endl;

    while (std::cin >> num)
    {
        numbers.push_back(num);
    }
    
    int count = 0;
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, [&count](int acc, int x) 
    {
        if (x > 0)
        {
            count++;
            return acc + x;
        }
        return acc;  
    });
    std::cout << sum << std::endl;

    double arithmeticMean = 0;
    arithmeticMean = sum / count;

    std::cout << arithmeticMean << std::endl;

    return 0;

}