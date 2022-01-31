#include <iostream>
#include "List.h"

int main()
{
    List<int> mainList = List<int>();
    mainList.pushFront(12);
    mainList.pushBack(11);
    mainList.insert(11, 1);
    mainList.insert(23, 2);
    mainList.print();
    mainList.remove(11);
    std::cout << "" << std::endl;
    mainList.print();
    return 0;
}