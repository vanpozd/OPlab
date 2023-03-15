#include <iostream>
#include <fstream>
#include <stdio.h>
//#include <cstring>
#include <string>
#include <string.h>
//#include <encryptin.cpp>

int main(int argc,char* argv[])
{
	std::string outputText, paroutputText, first_text;
    //open infile
    if(strcmp(*argv, "FileStream"))
    {
        std::string infilename, outfilename;
        std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
    	std::getline(std::cin, infilename);
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
                std::cout << "Ведіть текст у файл:" << infilename << std::endl;
                std::getline(std::cin, first_text);
                inputFile << first_text;
            }
        }
        //open outfile
        inputFile.close();
        outfilename = "encrypted" + infilename;
        std::ofstream outputFile(outfilename);
        if (!outputFile.is_open()) 
        {
            std::cout << "[ERROR] Помилка при створенні файлу: " << outfilename << std::endl;
        }
        else
        {
            std::cout << "Вихідний файл: " << outfilename << std::endl;
        }

        char c;
        while (inputFile.get(c)) 
        {
            if ((int)c % 2 == 0) 
            {
                paroutputText = paroutputText + c;
            }
            else 
            {
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
    else if(strcmp(*argv, "FilePointer"))
    {
        FILE* inpointer;
        FILE* outpointer;
        char infilename[30];
        char outfilename[30] = "encrypted";
        std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
        scanf("%s", infilename);
        if ((inpointer = fopen(infilename, "r")) == NULL)
        {
            std::cout << "Такго файлу не знайдено.\n" << std::endl;
            if((inpointer = fopen(infilename, "a")) == NULL)
            {
                std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
            }
            else
            {
                std::cout << "Ведіть текст у файл:" << infilename << std::endl;
                std::getline(std::cin, first_text);
                const char* text_buf = first_text.c_str();
                fprintf(inpointer,"%s",text_buf);
            }
        }
        fclose(inpointer);
        FILE* inpointer;
        //open outfile
        strcat(outfilename, infilename);
        if((outpointer = fopen(outfilename, "a")) == NULL)
        {
            std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
        }
        else
        {
            std::cout << "Вихідний файл: " << outfilename << std::endl;
        }

        char c;
        while ((c = fgetc(inpointer)) != EOF) 
        { 
            if (ftell(inpointer) % 2 == 0)
            {
                paroutputText = paroutputText + c;
            }
            else 
            {
                outputText = outputText + c;
            }
        }
        outputText = paroutputText + outputText;
        const char* text_buf = outputText.c_str();
        fprintf(outpointer,"%s",text_buf);
        fclose(inpointer);
        fclose(outpointer);
    }
    else
    {
        std::cout << "[ERROR] Такого моду не існує." << std::endl;
        return 1;
    }
}