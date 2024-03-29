#include <iostream>
#include <typeinfo>
#include <string>
#include "class.cpp"

void printMenu();

int main() 
{
    bool isStringDataType;
    std::cout << "Choose data type:\n";
    std::cout << "1. String\n";
    std::cout << "2. Integer\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        DoublyLinkedList<std::string> list;
        std::string value;

        do {
            printMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Size of the list: " << list.getSize() << std::endl;
                    break;
                case 2:
                    std::cout << "Enter the value to search: ";
                    std::cin >> value;
                    if (list.find(value) != nullptr)
                        std::cout << "Element found." << std::endl;
                    else
                        std::cout << "Element not found." << std::endl;
                    break;
                case 3:
                    std::cout << "Enter the value to get its position: ";
                    std::cin >> value;
                    std::cout << "Position of the element: " << list.getPosition(value) << std::endl;
                    break;
                case 4:
                    std::cout << "Enter the value for the new element: ";
                    std::cin >> value;
                    list.insert(value);
                    std::cout << "Element inserted." << std::endl;
                    break;
                case 5:
                    list.setIteratorToBeginning();
                    std::cout << "Iterator moved to the beginning of the list." << std::endl;
                    break;
                case 6:
                    if (list.isEndOfList())
                        std::cout << "Iterator reached the end of the list." << std::endl;
                    else
                        std::cout << "Iterator has not reached the end of the list." << std::endl;
                    break;
                case 7:
                    if (list.isEndOfList())
                        std::cout << "Iterator reached the end of the list." << std::endl;
                    else
                        std::cout << "Current value using iterator: " << list.getCurrentValue() << std::endl;
                    break;
                case 8:
                    list.moveToPrevious();
                    std::cout << "Iterator moved to the previous element." << std::endl;
                    break;
                case 9:
                    list.moveToNext();
                    std::cout << "Iterator moved to the next element." << std::endl;
                    break;
                case 0:
                    std::cout << "Exiting the program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }

            std::cout << std::endl;

        } while (choice != 0);
    }
    else if (choice == 2)
    {
        DoublyLinkedList<int> list;
        int value;

        do {
            printMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Size of the list: " << list.getSize() << std::endl;
                    break;
                case 2:
                    std::cout << "Enter the value to search: ";
                    std::cin >> value;
                    if (list.find(value) != nullptr)
                        std::cout << "Element found." << std::endl;
                    else
                        std::cout << "Element not found." << std::endl;
                    break;
                case 3:
                    std::cout << "Enter the value to get its position: ";
                    std::cin >> value;
                    std::cout << "Position of the element: " << list.getPosition(value) << std::endl;
                    break;
                case 4:
                    std::cout << "Enter the value for the new element: ";
                    std::cin >> value;
                    list.insert(value);
                    std::cout << "Element inserted." << std::endl;
                    break;
                case 5:
                    list.setIteratorToBeginning();
                    std::cout << "Iterator moved to the beginning of the list." << std::endl;
                    break;
                case 6:
                    if (list.isEndOfList())
                        std::cout << "Iterator reached the end of the list." << std::endl;
                    else
                        std::cout << "Iterator has not reached the end of the list." << std::endl;
                    break;
                case 7:
                    if (list.isEndOfList())
                        std::cout << "Iterator reached the end of the list." << std::endl;
                    else
                        std::cout << "Current value using iterator: " << list.getCurrentValue() << std::endl;
                    break;
                case 8:
                    list.moveToPrevious();
                    std::cout << "Iterator moved to the previous element." << std::endl;
                    break;
                case 9:
                    list.moveToNext();
                    std::cout << "Iterator moved to the next element." << std::endl;
                    break;
                case 0:
                    std::cout << "Exiting the program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }

            std::cout << std::endl;

        } while (choice != 0);
    }
    else 
    {
        std::cout << "Invalid choice. Exiting the program..." << std::endl;
    }

    return 0;
}

void printMenu() 
{
    std::cout << "====== Doubly Linked List Menu ======" << std::endl;
    std::cout << "1. Get size of the list" << std::endl;
    std::cout << "2. Search for an element" << std::endl;
    std::cout << "3. Get position of an element" << std::endl;
    std::cout << "4. Insert a new element" << std::endl;
    std::cout << "5. Move iterator to the beginning of the list" << std::endl;
    std::cout << "6. Check if iterator reached the end of the list" << std::endl;
    std::cout << "7. Get current value using iterator" << std::endl;
    std::cout << "8. Move iterator to the previous element" << std::endl;
    std::cout << "9. Move iterator to the next element" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "=====================================" << std::endl;
}
