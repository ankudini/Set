#include "UIntSet.h"

#include <iostream>

int main() 
{
    CustomContainers::UIntSet uIntSet;
    uIntSet.insert(2);
    uIntSet.insert(22);
    uIntSet.insert(22);
    uIntSet.insert(13);
    uIntSet.insert(43);
    uIntSet.insert(9);
    uIntSet.insert(61);
    uIntSet.insert(15);
    uIntSet.insert(3);
    uIntSet.insert(323);
    uIntSet.insert(100);
    uIntSet.print();
    std::cout << "Element 22 is " << (uIntSet.find(22) ? "found" : " not found") << std::endl;
    return 0;
}