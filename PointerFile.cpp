#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
//#include "encripting.cpp"

void output_printer(std::string,char*,char);
char* point_infilename();

std::string input_reader(char* infilename)
{
	std::string compline;
	FILE* rinpointer;
	FILE* inpointer;
	char buftext[100];
	char fintext[1000];
	char filefill[1000];
	if ((rinpointer = fopen(infilename, "r")) == NULL)
	{
		std::cout << "Такго файлу не знайдено." << std::endl;
		fclose(rinpointer);
		if((inpointer = fopen(infilename, "a")) == NULL)
		{
			std::cout << "[ERROR] Помилка при створенні файлу" << std::endl;
		}
		else
		{
			std::cout << "Ведіть текст у файл" << std::endl;
			scanf("%s", buftext);
			fseek(inpointer, 0, SEEK_SET);
			fprintf(inpointer,"%s",buftext);
			fclose(inpointer);
		}
	}
	else
	{
		printf("Текст у файлі:\n");
		do
		{
			fgets(filefill, 200, rinpointer);
			printf("%s", filefill);
		} while (!feof(rinpointer));
		fclose(rinpointer);
		std::cout << "\nЧи хочете ви додати текст до файлу перед шифруванням?(+/-)" << std::endl;
		std::cin >> compline;
		if(compline.compare("+") == 0)
		{
			inpointer = fopen(infilename, "a");
			printf("Введіть текст (напишіть EXIT, щоб вийти):\n");
			while (true) 
			{
				scanf("%s", buftext);
				if (strcmp(buftext, "EXIT") == 0)
				{
					break;
				}
				strcat(fintext, buftext);
			}
			fseek(inpointer, 0, SEEK_END);
			fprintf(inpointer,"%s",fintext);
			fclose(inpointer);
		}
	}
	char b;
	std::cout << "Введіть букву яку хочете прибрати з новогу файлу:" << std::endl;
	std::cin >> b;
	inpointer = fopen(infilename, "r");
	std::string paroutputText, outputText;
	do
	{
		fgets(filefill, 200, rinpointer);
		paroutputText = encripting_pointer(filefill);
		if(strlen(filefill) % 2 == 0)
		{
			output_printer(paroutputText,infilename,b);
			outputText += paroutputText;
		}
		else
		{
			outputText += paroutputText;
		}
	} while (!feof(rinpointer));
/*
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
	std::cout << "Текст після шифрування:" << outputText << std::endl;
*/
	return outputText;
}

void output_printer(std::string outputText,char* infilename,char b)
{
	FILE* outpointer;
	char outfilename[30] = "encrypted";
	char fincout[200];
	char outputFinal[200];
	int j = 0;
	strcat(outfilename, infilename);
	outpointer = fopen(outfilename, "a");
	const char* text_buf = outputText.c_str();
	strcpy(fincout,text_buf);
	for(int i = 0; i < strlen(fincout);i++)
	{
		if(fincout[i] != b)
		{
			outputFinal[j] = fincout[i];
			j++;
		}
	}
	fprintf(outpointer,"%s",outputFinal);
	fclose(outpointer);
}
void final_point(std::string outputText, char* infilename)
{
	FILE* outputPoint;
	outputPoint = fopen(infilename, "w");
	const char* text_buf = outputText.c_str();
	fprintf(outputPoint,"%s",text_buf);
	fclose(outputPoint);
}
char* point_infilename()
{
	char infilename[30];
	std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
	scanf("%s", infilename);
	return infilename;
}