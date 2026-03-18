#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

std::vector<double> readNumbers() 
{
    std::vector<double> numbers;
    double num;

    std::cout << "Введите числа для массива через пробел (Enter, затем Ctrl+Z/D для конца)" << std::endl;

    while (std::cin >> num)
    {
        numbers.push_back(num);
    }
    return numbers;
}

struct SumAndCount
{
    double sum;
    int count;
};

SumAndCount calculatePositiveSumAndCount(const std::vector<double> numbers)
{
    SumAndCount result = {0.0, 0};
    result.sum = std::accumulate(numbers.begin(), numbers.end(), 0.0, [&result](double acc, double x) 
    {
        if (x > 0)
        {
            result.count++;
            return acc + x;
        }
        return acc;  
    });

    return result;
}

double calculateArithmeticMean(double sum, int count)
{
    double arithmeticMean = 0;
    if (count == 0)
    {
        arithmeticMean = 0;
    } 
    else
    {
        arithmeticMean = sum / count;
    }

    return arithmeticMean;
}

void addMeanToAll(std::vector<double>& numbers, double arithmeticMean) {
    for (double& y : numbers) {
        y += arithmeticMean;
    }
}

void printResults(double sum, double arithmeticMean, const std::vector<double>& numbers) {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << sum << std::endl;
    std::cout << arithmeticMean << std::endl;
    
    for (double z : numbers) {
        std::cout << z << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<double> numbers = readNumbers();
    
    SumAndCount result = calculatePositiveSumAndCount(numbers);

    double arithmeticMean = calculateArithmeticMean(result.sum, result.count);

    addMeanToAll(numbers, arithmeticMean);

    std::sort(numbers.begin(), numbers.end());

    printResults(result.sum, arithmeticMean, numbers);

    return 0;

}