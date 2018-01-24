#include "RedBlackTree.h"

#include <utility>

namespace CustomContainers {

class UIntSet {
    RedBlackTree tree;
    
public:
    // iterator typdef
    // typedef RedBlackTree::Iterator Iterator;
    
    // default constructor
    UIntSet() : tree() {}
    
    // copy-constructor
    UIntSet(const UIntSet& iSet) : tree(iSet.tree) {}
    
    // move-constructor
    UIntSet(UIntSet&& iSet) : tree(std::move(iSet.tree)) {}
    
    // copy-assignment operator
    UIntSet& operator=(const UIntSet& iSet) 
    {
        if(&iSet == this) return *this;
        tree = iSet.tree;
    }
    
    // move-assignment operator
    UIntSet& operator=(UIntSet&& iSet) 
    {
        if(&iSet == this) return *this;
        tree = std::move(iSet.tree);        
    }
    
    // destructor
    ~UIntSet() {}

    
    // modification
    bool insert(unsigned int iValue) 
    {
        return tree.insert(iValue);
    }
    
    bool erase(unsigned int iValue)
    {
        return tree.erase(iValue); // TODO: Currently not finished. Implement RedBlackTree::erase.
    }
    
    void clear()
    {
        tree.clear();
    }
    
    
    // search
    bool find(unsigned int iValue) 
    {
        return tree.find(iValue);
    }
    
    // capacity
    unsigned int size() 
    { 
        return tree.size(); 
    }
    
    bool empty() 
    { 
        return tree.size() == 0; 
    }
    
    // print 
    void print()
    {
        return tree.print();
    }
};

}