#include <iostream>
#include <fstream>
#include <string>
#include "Streamlab.h"

int main() 
{
    FILE* fpointer;
    char chartoencrypt;
	std::string infilename, outfilename, outputText, paroutputText;
    cout << "Введіть назфу файлу який треба зашифрувати: ";
	std::getline(std::cin, infilename);
	outfilename = "encrypted" + infilename;
    //open infile
    std::ifstream inputFile(infilename);
	if (!inputFile.is_open()) 
    {
        std::cout << "В створених файлах не знайдено файлу з імʼям: " << infilename << std::endl;
        std::ofstream inputFile(infilename);
        if (!inputFile.is_open()) 
        {
            std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
		}
        else
        {
            std::cout << "Створено файл з імʼям: " << infilename << std::endl;
        }
    }

    //open outfile
    std::ofstream outputFile(outfilename);
	if (!inputFile.is_open()) 
    {
        std::cout << "В створених файлах не знайдено файлу з імʼям: " << outfilename << std::endl;
        std::ofstream outputFile(outfilename);
        if (!inputFile.is_open()) 
        {
            std::cout << "[ERROR] Помилка при створенні файлу: " << outfilename << std::endl;
		}
        else
        {
            std::cout << "Створено файл з імʼям: " << outfilename << std::endl;
        }
    }

    // reading end encriptin file 
    char c;
    while (inputFile.get(c)) {
        if ((int)c % 2 == 0) {
            paroutputText = paroutputText + c;
        }
        else {
            outputText = outputText + c;
        }
    }
    outputText = paroutputText + outputText; 
    std::cout << outputText << std::endl;

    outputFile << outputText;
    outputFile.close();
    
    inputFile.close();

    std::cout << "Текст було успішно зашифровано з файлу " << infilename << " до файлу " << outfilename << std::endl;

    return 0;
}

void openfileStream(string infilename)
{	
	std::ifstream inputFile(infilename);
	if (!inputFile.is_open()) 
    {
        std::cout << "В створених файлах не знайдено файлу з імʼям: " << infilename << std::endl;
        std::ofstream inputFile(infilename);
        if (!inputFile.is_open()) 
        {
            std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
		}
        else
        {
            std::cout << "Створено файл з імʼям: " << infilename << std::endl;
        }
    }
}
