#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "encripting.cpp"

void output(std::string,std::string,char);

std::string input_filename();

void input_encripting(std::string infilename)
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
		std::cin.ignore();
		if(compline.compare("+") == 0)
		{
			std::ofstream inputFile;
			inputFile.open(infilename, std::ios::app);
			std::cout << "Ведіть текст у файл\n" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, first_text);
			inputFile << first_text;
			inputFile.close();
		}
	}
	char b;
	int count = 0;
	std::cout << "Введіть букву яку хочете прибрати з новогу файлу:" << std::endl;
	b = std::cin.get();
	std::cin.ignore();
	std::ifstream inputFile(infilename);
	while(getline(inputFile, line))
	{
		std::string anline = encripting_stream(line);
		if(anline.length() % 2 == 0)
		{
			output(infilename, anline, b);
			if(count != 0)
			{
				anline = "\n" + anline;
			}
			outputText += anline;
		}
		else
		{
			if(count != 0)
			{
				anline = "\n" + anline;
			}
			outputText += anline;
		}
		count++;
	}
	std::cout << "Текст після шифрування:\n" << outputText << std::endl;
	inputFile.close();
	std::ofstream inputFiler(infilename,std::ofstream::trunc);
	inputFiler << outputText;
	inputFiler.close();
}

std::string input_filename()
{
	std::string infilename;
	std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
	std::getline(std::cin, infilename);
	return infilename;
}

void output(std::string infilename,std::string outputText, char testchar)
{
	std::string outfilename = "encrypted" + infilename;
	std::ifstream outputFiler(outfilename);
	if(outputFiler.tellg() == 0)
	{
		outputText = "\n" + outputText;
	}
	outputFiler.close();
	std::ofstream outputFile;
	outputFile.open(outfilename, std::ios::app);
	std::cin.ignore();
	if (!outputFile.is_open()) 
	{
		std::cout << "[ERROR] Помилка при створенні файлу: " << outfilename << std::endl;
	}
	int i = 0;
	char ss;
	std::string finaloutput;
	while((ss = outputText[i]))
	{
		if(ss != testchar)
		{

			finaloutput = finaloutput + ss;
		}
		i++;
	}
	outputFile << finaloutput;
	outputFile.close();
}