#include <iostream>
#include "List.h"

int main()
{
    List<int> list = List<int>();
    list.destroy();
    list.insert(8, 0);
    List<int> list2 = List<int>(list);

    for (Iterator<int> iter = list.begin(); iter != list.end(); ++iter)
    {
        if (list.contains(8))
            std::cout << "FUCKYOU";
    }

    list.destroy();
    list2.insert(6, 0);
    list.destroy();
    list2.remove(6);
    list2.remove(6);
    list.print();
    list2.print();
}