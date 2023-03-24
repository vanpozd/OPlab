#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "encripting.cpp"

void output(std::string,std::string,char,int);
void finalout(std::string,std::string);
std::string input_filename();
char letter_to_remove();
std::string outfile_create(std::string);
void new_file_stream(std::string);
void file_fill_adder(std::string);

std::string input_encripting(std::string infilename)
{
	std::string first_text,outputText,paroutputText,line,compline;
	std::ifstream inputFiler(infilename);
	if (!inputFiler.is_open()) 
	{
		new_file_stream(infilename);
	}
	else
	{
		std::cout << "Текст у файлі:" << std::endl;
		while (std::getline(inputFiler, line))
		{
        	std::cout << line << std::endl;
    	}
		std::cout << "Чи хочете ви додати текст до файлу перед шифруванням?(+/-)" << std::endl;
		std::cin >> compline;
		if(compline.compare("+") == 0)
		{
			file_fill_adder(infilename);
		}
	}
	inputFiler.close();
	std::ifstream inputFile(infilename);
	char b = letter_to_remove();
	int line_num = 0;
	int outcounter = 0;
	std::string outfilename = outfile_create(infilename);
	while(getline(inputFile, line))
	{
		std::string anline = encripting_stream(line);
		if(anline.length() % 2 == 0)
		{
			output(infilename,anline,b,outcounter);
			if(line_num != 0)
			{
				anline = "\n" + anline;
			}
			outputText += anline;
			outcounter++;
		}
		else
		{
			if(line_num != 0)
			{
				anline = "\n" + anline;
			}
			outputText += anline;
		}
		line_num++;
	}
	std::cout << "Текст після шифрування:\n" << outputText << std::endl;
	inputFile.close();
	return outputText;
}

char letter_to_remove()
{
	char b;
	std::cout << "Введіть букву яку хочете прибрати з новогу файлу:" << std::endl;
	std::cin >> b;
	return b;
}
std::string outfile_create(std::string infilename)
{
	std::string outfilename = "encrypted" + infilename;
	std::ofstream cleaner(outfilename,std::ofstream::trunc);
	cleaner.close();
	return outfilename;
}
void new_file_stream(std::string infilename)
{
	std::string first_text;
	std::cout << "Такго файлу не знайдено." << std::endl;
	std::ofstream inputFile(infilename);
	if (!inputFile.is_open()) 
	{
		std::cout << "[ERROR] Помилка при створенні файлу" << std::endl;
	}
	else
	{
		file_fill_adder(infilename);
	}
}
void file_fill_adder(std::string infilename)
{
	std::string first_text;
	std::ofstream inputFile;
	inputFile.open(infilename, std::ios::app);
	std::cout << "Введіть текст (напишіть EXIT, щоб вийти):\n";
	while (true) 
	{
		std::getline(std::cin, first_text);
		if (first_text.compare("EXIT") == 0) 
		{
			break;
		}
		first_text += "\n";
		inputFile << first_text;
	}
	inputFile.close();
}
std::string input_filename()
{
	std::string infilename;
	std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
	std::getline(std::cin, infilename);
	return infilename;
}
void output(std::string infilename,std::string outputText, char testchar,int outcounter)
{
	std::string outfilename = "encrypted" + infilename;
	std::ifstream outputFiler(outfilename);
	if(outcounter != 0)
	{
		outputText = "\n" + outputText;
	}
	outputFiler.close();
	std::ofstream outputFile;
	outputFile.open(outfilename, std::ios::app);
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
void finalout(std::string infilename,std::string outputText)
{
	std::ofstream inputFile(infilename,std::ofstream::trunc);
	inputFile << outputText;
	inputFile.close();
}