#include "UIntSet.h"

#include <iostream>

int main() 
{
	CustomContainers::UIntSet uIntSet;
    uIntSet.insert(2);
    uIntSet.insert(22);
    uIntSet.insert(13);
    uIntSet.insert(43);
    uIntSet.insert(9);
    uIntSet.insert(22);
    uIntSet.insert(11);
    //uIntSet.insert(35);
    //uIntSet.insert(19);
    std::cout << uIntSet.size();
	return 0;
}