#include "stdafx.h"

// Возвращает результат замены всех вхождения строки searchString внутри строки subject на replacementString
std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	// Если строка searchString пустая, то возвращается subject
	if (searchString.empty())
	{
		return subject;
	}

	//тип данных для чисел, обозначающих размер в нашем случае счет позиции
	size_t pos = 0;
	//тип возращаемого значение(результат замены)
	std::string result;
	//поиск подстроки для замены и сама замена 
	while (pos < subject.length())
	{
		// Находим позицию искомой строки, начиная с pos
		size_t foundPos = subject.find(searchString, pos);

		//если foundPos определяется как "позиция не найдена" цикл заканчивается в результат записывается subject на позицию pos длинной subject.length()-pos
		if (foundPos == std::string::npos) 
		{
			result.append(subject, pos, subject.length() - pos);
			break;
		}ы
		// В результирующую строку записываем текст из диапазона [pos,foundPos)
		result.append(subject, pos, foundPos - pos);
		result.append(replacementString);

		pos = foundPos + searchString.length();
	}
	return result;
}

//функция для работы с файлами
//TODO выяснить что такое ifstream, как программа работает одинаково и с файлом и консолью
void CopyStreamWithReplacement(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string line;

	while (std::getline(input, line))
	{
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
}

//проверка на ошибки если есть ошибка возвращает false есои нет то true
bool CopyFileWithReplacement(const std::string& inputFileName, const std::string& outputFileName, 
							const std::string& search, const std::string& replace)
	{
		std::ifstream inputFile;
		inputFile.open(inputFileName);
		if(!inputFile.is_open())
		{
			return false;
		}

		std::ofstream outputFile;
		outputFile.open(outputFileName);
		if(!outputFile.is_open())
		{
			return false;
		}

		CopyStreamWithReplacement(inputFile, outputFile, search, replace);

		outputFile.flush();
	
		return true;
	}

int main(int argc, char* argv[])
{

	if (argc == 1)
	{
		//режим stdin
		std::string search;
		if (!std::getline(std::cin, search)) 
		{
			std::cout << "ERROR";
			//TODO узнать какие коды бывают из main какой return
			return 0;
		}

		std::string replace;
		if (!std::getline(std::cin, replace)) 
		{
			std::cout << "ERROR";    
			return 0;
		}

		std::string firstLine;
		//TODO если нет второй третьей и тд линии лучше назвать по другому 
		if (!std::getline(std::cin, firstLine)) 
		{
			std::cout << replace;
			return 0;
		}

		std::cout << ReplaceString(firstLine, search, replace) << "\n";

		//важно для обработки более 1 строки исходного текста, если убрать будет обрабатыватся только одна
		CopyStreamWithReplacement(std::cin, std::cout, search, replace);

		return 0;
	}

	if (argc != 5)
	{
		std::cout << "Invalid argument count\n"
				<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	std::string search = argv[3];
	std::string replace = argv[4];

	if (!CopyFileWithReplacement(argv[1], argv[2], search, replace))
	{
		std::cout << "ERROR";
		return 1;
	}

	return 0;
}