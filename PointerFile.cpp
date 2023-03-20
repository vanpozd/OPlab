#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>

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
		do
		{
			fgets(filefill, 200, rinpointer);
			printf("Текст у файлі:\n%s", filefill);
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
				// Виконуємо операції зі стрічкою, наприклад, вивід на екран:
				strcat(fintext, buftext);
			}
			fseek(inpointer, 0, SEEK_END);
			fprintf(inpointer,"%s",fintext);
			fclose(inpointer);
		}
	}
	inpointer = fopen(infilename, "r");
	std::string paroutputText, outputText;
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
	return outputText;
}

void outout_printer(std::string outputText,char* infilename)
{
	FILE* outpointer;
	char outfilename[30] = "encrypted";
	strcat(outfilename, infilename);
	if((outpointer = fopen(outfilename, "a")) == NULL)
	{
		std::cout << "[ERROR] Помилка при створенні файлу: " << infilename << std::endl;
	}
	else
	{
		std::cout << "Вихідний файл: " << outfilename << std::endl;
	}
	const char* text_buf = outputText.c_str();
	fprintf(outpointer,"%s",text_buf);
	fclose(outpointer);
}

char* point_infilename()
{
	char infilename[30];
	std::cout << "Введіть назфу файлу який треба зашифрувати: " << std::endl;
	scanf("%s", infilename);
	return infilename;
}