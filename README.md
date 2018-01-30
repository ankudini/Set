# UIntSet
This repository contains an unsigned int set class implemented as a red-black tree for fast (log(n)) search even for worst cases.
Note that currently this implementation:
1) Is NOT exception-safe (TODO: 1)
2) Has no erase implementation (TODO: 2)

TODO:
1) Move from raw pointers to std::shared_ptr<Node> for left and right and std::weak_ptr<Node> for parent.
2) Implement erase member function
3) Change this class to - template Set<typename T, typename Compare>
4) Add iterators and iterator-based operations

Compiled for testing with gcc 6.4.0 via g++ src/main.cpp src/UIntSet.h src/RedBlackTree.h src/RedBlackTree.cpp