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
    mainList.pushFront(23);
    mainList.insert(23, 1);
    mainList.pushBack(54);
    mainList.remove(11);
    mainList.remove(12);
    std::cout << "" << std::endl;
    if (mainList.contains(11))
        std::cout << "Contains 11" << std::endl;
    std::cout << "" << std::endl;
    mainList.sort();

    List<int> mainList2 = mainList;
    mainList2.pushFront(20);
    mainList2.pushBack(41);
    mainList2.insert(4, 1);
    mainList2.insert(4, 1);
    mainList2.remove(20);
    mainList2.sort();
    mainList2.print();
    if (!mainList2.isEmpty()) {
        std::cout << "List Size : ";
        std::cout << mainList2.getLength() << std::endl;
        mainList2.destroy();
        std::cout << "List Destroyed" << std::endl;
    }
    return 0;
}