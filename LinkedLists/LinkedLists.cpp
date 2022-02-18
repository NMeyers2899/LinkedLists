#include <iostream>
#include "List.h"

int main()
{
    // Creates a new, empty list.
    List<int> list = List<int>();
    // Inserts three new numbers into the list then prints them.
    list.insert(8, 0);
    list.insert(7, 1);
    list.insert(10, 2);
    std::cout << "The List :" << std::endl;
    list.print();
    system("pause");
    system("cls");

    // Checks to see if the list contains the number eight.
    std::cout << "Let's see if this list contains the number 8." << std::endl;
    if (list.contains(8))
        // If it contains eight, it prints out this line.
        std::cout << "There it is, the number 8!" << std::endl;
    system("pause");
    system("cls");

    // Inserts new numbers into the list out of order.
    list.pushFront(15);
    list.pushBack(2);
    std::cout << "New List :" << std::endl;
    list.print();
    system("pause");
    system("cls");
    std::cout << "This list is out of order! Let's fix that." << std::endl;
    // Sorts the list and displays it to the user.
    list.sort();
    list.print();
    std::cout << "Ah, now that is much better!" << std::endl;
    system("pause");
    system("cls");

    // Removes all elements from the list and displays the final message to the user.
    std::cout << "Well, that's all we have. Time to empty the list." << std::endl;
    list.destroy();
    if (list.isEmpty())
        std::cout << "List destroyed. Thank you for participating." << std::endl;
}