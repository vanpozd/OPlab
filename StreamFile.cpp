#include <iostream>
#include <fstream>
#include <string>

std::string input_filename()
{
	std::string infilename;
	std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
	std::getline(std::cin, infilename);
	return infilename;
}

std::string input_encripting(std::string infilename)
{
	std::string first_text,outputText,paroutputText,line,compline;
	std::ifstream rinputFile(infilename);
	if (!rinputFile.is_open()) 
	{
		std::cout << "В створених файлах не знайдено файлу з імʼям: " << infilename << std::endl;
		std::ofstream inputFile(infilename);
		if (!inputFile.is_open()) 
		{
			std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
		}
		else
		{
			std::cout << "Ведіть текст у файл" << std::endl;
			std::getline(std::cin, first_text);
			inputFile << first_text;
			inputFile.close();
		}
	}
	else
	{
		std::cout << "Текст у файлі:" << std::endl;
		while (std::getline(rinputFile, line))
		{
        	std::cout << line << std::endl;
    	}
		rinputFile.close();
		std::cout << "Чи хочете ви додати текст до файлу перед шифруванням?(+/-)" << std::endl;
		std::cin >> compline;
		if(compline.compare("+") == 0)
		{
			std::ofstream inputFile;
			inputFile.open(infilename, std::ios::app);
			std::cout << "Ведіть текст у файл\n" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, first_text);
			//line += first_text;
			inputFile << first_text;
			inputFile.close();
		}
	}
	std::ifstream inputFile(infilename);
	char c;
	int i = 1;
	while (inputFile.get(c)) 
	{
		if (i % 2 == 0) 
		{
			paroutputText = paroutputText + c;
		}
		else 
		{
			outputText = outputText + c;
		}
	i++;
	}
	outputText = paroutputText + outputText;
	std::cout << "Текст після шифрування:" << outputText << std::endl;
	return outputText;
	inputFile.close();
}

void output(std::string infilename,std::string outputText)
{
	std::string outfilename = "encrypted" + infilename;
	std::ofstream outputFile(outfilename);
	if (!outputFile.is_open()) 
	{
		std::cout << "[ERROR] Помилка при створенні файлу: " << outfilename << std::endl;
	}
	else
	{
		std::cout << "Вихідний файл: " << outfilename << std::endl;
	}
	outputFile << outputText;
	outputFile.close();
}