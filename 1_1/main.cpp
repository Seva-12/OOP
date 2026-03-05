#include <cassert>
#include <functional> // Необходим для std::function
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

using FindStringCallback = function<void(int lineIndex, const string& line, size_t foundPos)>;

bool FindStringInStream(
	istream& haystack,
	const string& needle,
	const FindStringCallback& callback = FindStringCallback())
{
	string line;
	bool found = false;
	for (int lineIndex = 1; getline(haystack, line); ++lineIndex)
	{
		auto pos = line.find(needle);
		if (pos != string::npos)
		{
			found = true;
			// Передаем в функцию обратного вызова информацию о
			// первом найденном вхождении подстроки
			if (callback)
			{
				callback(lineIndex, line, pos);
			}
		}
	}
	return found;
}

void PrintFoundLineIndex(int lineIndex, const string& /*line*/, size_t /*foundPos*/)
{
	cout << lineIndex << endl;
}

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        cout << "Usage: findtext.exe <file name> <text to search>" << endl;
        return 1;
    }

    ifstream file(argv[1]);

    if (!file.is_open())
    {
        cout << "ERROR: Failed to open file: " << argv[1] << endl;
        return 1;
    }

    if (!FindStringInStream(file, argv[2], PrintFoundLineIndex))
    {
        cout << "Text not found" << endl;
        return 1;
    }

    return 0;
}