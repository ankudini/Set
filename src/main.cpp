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
    
    CustomContainers::UIntSet copyConstructed(uIntSet);
    std::cout << "CopyConstructed" << std::endl;
    copyConstructed.print();
    std::cout << std::endl;
    
    
    std::cout << "CopyAssigned" << std::endl;
    CustomContainers::UIntSet copyAssigned;
    copyAssigned.insert(9999);
    copyAssigned = uIntSet;
    std::cout << "Element 22 is " << (copyAssigned.find(22) ? "found" : " not found") << std::endl;
    
    std::cout << "MoveAssigned" << std::endl;
    CustomContainers::UIntSet moveAssigned;
    moveAssigned.insert(555555);
    moveAssigned = std::move(copyAssigned);
    std::cout << "Size is " << moveAssigned.size() << std::endl;
    

    return 0;
}