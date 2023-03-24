#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>


void output_printer(std::string,char*,char,int);
char* point_infilename();
int point_file_reader(char* );
void point_file_filler(char*);
char point_char_taker();

std::string input_reader(char* infilename)
{
	std::string compline;
	FILE* rinpointer;
	FILE* inpointer;
	char buftext[100];
	char fintext[1000];
	char filefill[1000];
	if ((inpointer = fopen(infilename, "r")) == NULL)
	{
		std::cout << "Такго файлу не знайдено." << std::endl;
		fclose(inpointer);
		point_file_filler(infilename);
	}
	else
	{
		if(point_file_reader(infilename) == 0)
		{
			point_file_filler(infilename);
		}
	}
	char b = point_char_taker();
	int line_num = 0;
	inpointer = fopen(infilename, "r");
	std::string paroutputText, outputText;
	do
	{
		fgets(filefill, 200, inpointer);
		paroutputText = encripting_pointer(filefill);
		std::cout << paroutputText.length();
		if((paroutputText.length()-1) % 2 == 0)
		{
			output_printer(paroutputText,infilename,b,line_num);
			outputText += paroutputText;
			line_num++;
		}
		else if(((paroutputText.length()-1) % 2 < 0) || ((paroutputText.length()-1) % 2 > 0))
		{
			outputText += paroutputText;
		}
	} while (!feof(inpointer));
	fclose(inpointer);
	std::cout << "Текст після шифрування:\n" << outputText << std::endl;
	return outputText;
}

void output_printer(std::string outputText,char* infilename,char b,int line_num)
{
	FILE* outpointer;
	char outfilename[30] = "encrypted";
	int j = 0;
	strcat(outfilename, infilename);
	outpointer = fopen(outfilename, "a");
	std::string finaloutput;
	char ss;
	while((ss = outputText[j]))
	{
		if(ss != b)
		{
			finaloutput = finaloutput + ss;
		}
		j++;
	}
	const char* text_buf = finaloutput.c_str();
	fseek(outpointer, 0, SEEK_END);
	fprintf(outpointer,"%s",text_buf);
	fclose(outpointer);
}
char point_char_taker()
{
	char b;
	std::cout << "Введіть букву яку хочете прибрати з новогу файлу:" << std::endl;
	std::cin >> b;
	return b;
}
void point_file_filler(char* infilename)
{
	FILE* inpointer;
	std::string first_text, fintext;
	inpointer = fopen(infilename, "a");
	printf("Введіть текст (напишіть EXIT, щоб вийти):\n");
	while (true) 
	{
		std::getline(std::cin, first_text);
		if (first_text.compare("EXIT") == 0) 
		{
			break;
		}
		first_text = "\n" + first_text;
		if(first_text.compare("\n") != 0)
		{
			const char* textbuf = first_text.c_str();
			fseek(inpointer, 0, SEEK_END);
			fprintf(inpointer,"%s",textbuf);
			fflush(inpointer);
		}
	}
	fclose(inpointer);
}
int point_file_reader(char* infilename)
{
	char filefill[300];
	FILE* inpointer;
	inpointer = fopen(infilename, "r");
	printf("Текст у файлі:\n");
		do
		{
			fgets(filefill, 200, inpointer);
			printf("%s", filefill);
		} while (!feof(inpointer));
	fclose(inpointer);
	std::string compline;
	std::cout << "\nЧи хочете ви додати текст?(+/-)" << std::endl;
	std::cin >> compline;
	if(compline.compare("+") == 0)
	{
		return 0;
	}
	return 1;
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