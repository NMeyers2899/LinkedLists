#include <iostream>
#include "List.h"

int main()
{
    List<int> mainList = List<int>();
    mainList.pushFront(12);
    mainList.pushBack(11);
    mainList.insert(11, 1);
    mainList.insert(23, 2);
    mainList.pushFront(15);
    mainList.print();
    mainList.remove(11);
    std::cout << "" << std::endl;
    mainList.print();
    if (mainList.contains(11))
        std::cout << "Contains 11" << std::endl;
    std::cout << "" << std::endl;
    mainList.sort();
    mainList.print();
    return 0;
}