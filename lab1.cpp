#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "encripting.cpp"
#include "StreamFile.cpp"
#include "PointerFile.cpp"

int main(int argc, char* argv[])
{
	if(std::strcmp(argv[1], "FileStream") == 0)
	{
		std::string infilename = input_filename();
		std::string outputText = input_encripting(infilename);
		finalout(infilename,outputText);
	}
	else if(std::strcmp(argv[1], "FilePointer") == 0)
	{	
		char infilename[100];
		strcpy(infilename,point_infilename());
		std::string output_text = input_reader(infilename);
		final_point(output_text,infilename);
	}
	else
	{
		std::cout << "usage: ./lab1 FileStram or FilePointer" << std::endl;
		return 0;
	}
}