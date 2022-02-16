#include <iostream>
#include "List.h"

int main()
{
    List<int> list = List<int>();
    List<int> list2 = List<int>(list);
    list.insert(8, 0);
    list.destroy();
    list2.destroy();
    list2.insert(6, 0);
    list.destroy();
    list2.remove(6);
    list2.remove(6);
    list.print();
    list2.print();
}