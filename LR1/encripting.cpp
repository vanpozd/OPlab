#include <string>
#include <iostream>

std::string encripting_stream(std::string inputstring)
{
	std::string paroutputText, outputText;
	char c;
	int i = 0;
	while ((c = inputstring[i])) 
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
	outputText = outputText + paroutputText;
	return outputText;
}

std::string encripting_pointer(char* inputstring)
{
	std::string paroutputText, outputText;
	char c;
	int i = 0;
	while ((c = inputstring[i])) 
	{
		if(c != '\n')
		{
			if (i % 2 == 0)
			{
				paroutputText = paroutputText + c;
			}
			else 
			{
				outputText = outputText + c;
			}
		}
		else
		{
			paroutputText += "\n";
		}
		i++;
	}
	outputText = outputText + paroutputText;
	return outputText;
}