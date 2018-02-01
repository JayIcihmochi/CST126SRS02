#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <memory>

int main()
{
	const int MAX_NAME_LENGTH = 257;
	int numberOfNames = 0;
	int arrayLength = 2;
	char name[MAX_NAME_LENGTH];
	char ** arrayOfNames = new char*[arrayLength];

	while (std::cin.good())
	{
		for (;;)
		{
			const int checker = std::cin.peek();
			if (checker != '\n' && !std::cin.eof())
			{
				if (numberOfNames == arrayLength)
				{
					char ** temp = new char*[arrayLength];
					std::memcpy(temp, arrayOfNames, sizeof(temp[0]) * arrayLength);
					delete[] arrayOfNames;
					arrayLength *= 2;
					arrayOfNames = new char*[arrayLength];
					std::memcpy(arrayOfNames, temp, sizeof(arrayOfNames[0]) * arrayLength);
					delete[] temp;
				}
				std::cin >> std::setw(MAX_NAME_LENGTH - 1) >> name;

				char * copyName = new char[strlen(name) + 1];
				strcpy(copyName, name);

				arrayOfNames[numberOfNames] = copyName;

				numberOfNames++;
			}
			else
			{
				const int endLineCatcher = std::cin.get();
				break;
			}
		}

		int numberOfNamesPrint = numberOfNames;

		while (numberOfNamesPrint > 0)
		{
			--numberOfNamesPrint;
			std::cout << arrayOfNames[numberOfNamesPrint];
			if (numberOfNamesPrint != 0)
				std::cout << ' ';
		}
		std::cout << std::endl;

		while (numberOfNames > 0)
		{
			--numberOfNames;
			delete[] arrayOfNames[numberOfNames];
		}
	}

	delete[] arrayOfNames;
	return 0;
}