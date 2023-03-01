#include <iostream>
#include <fstream>
#include <string>

int main() 
{
	std::cout<<"Введіть назфу файлу який треба зашифрувати: ";
	std::string filename;
	std::getline(std::cin, filename);
    std::string outputFileName = "output.txt";
    std::string line;

    // Відкриття вхідного файлу для зчитування
    std::ifstream inputFile(filename);

    // Перевірка, чи відкрився файл
    if (!inputFile.is_open()) {
        std::cerr << "Помилка відкриття файлу " << inputFileName << std::endl;
        return 1;
    }

    // Відкриття вихідного файлу для запису
    std::ofstream outputFile(outputFileName);

    // Перевірка, чи відкрився файл
    if (!outputFile.is_open()) {
        std::cerr << "Помилка відкриття файлу " << outputFileName << std::endl;
        return 1;
    }

    // Зчитування тексту з вхідного файлу і запис у вихідний файл
    while (getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    // Закриття файлів
    inputFile.close();
    outputFile.close();

    std::cout << "Текст було успішно скопійовано з файлу " << filename << " до файлу " << outputFileName << std::endl;

    return 0;
}