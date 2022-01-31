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
    mainList.pushBack(54);
    mainList.print();
    mainList.remove(11);
    mainList.remove(12);
    std::cout << "" << std::endl;
    mainList.print();
    if (mainList.contains(11))
        std::cout << "Contains 11" << std::endl;
    std::cout << "" << std::endl;
    mainList.sort();
    mainList.print();

    List<int> mainList2 = List<int>();
    mainList2.pushFront(20);
    mainList2.pushBack(41);
    mainList.insert(4, 0);
    mainList2.sort();
    mainList2.print();
    return 0;
}