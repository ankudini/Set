namespace CustomContainers {
    
enum Color {RED, BLACK};
    
// Node class definition
struct Node {
    Node(unsigned int iValue)
    {
        color = RED;
        value = iValue;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    
    ~Node() 
    {
        delete left;
        delete right;
    }
    
    Color color;
    unsigned int value;
    Node* left;
    Node* right;
    Node* parent;
};
    
class RedBlackTree {
    // The root node of a tree used as a base data structure for the set
    Node* root;
    unsigned int treeSize;
    
public:
    // default constructor
    RedBlackTree() : root(nullptr) {}
    
    // copy-constructor
    RedBlackTree(const RedBlackTree& iTree) : root(nullptr)
    { 
        // copy all elements iterating through the whole iTree
    }
    
    // move-constructor
    RedBlackTree(RedBlackTree&& iTree)
    { 
        root = iTree.root;
        iTree.root = nullptr;
    }
    
    // copy-assignment operator
    RedBlackTree& operator=(const RedBlackTree& iTree) 
    {
        if(&iTree == this) return *this;
        
        // clear this set
        // copy all elements iterating through the whole iSet
    }
    
    // move-assignment operator
    RedBlackTree& operator=(RedBlackTree&& iTree) 
    {
        if(&iTree == this) return *this;
        
        root = iTree.root;
        iTree.root = nullptr;       
    }
    
    // destructor
    ~RedBlackTree() 
    {
        delete(root);
    }
    
    // modification
    bool insert(unsigned int iValue);
    
    bool erase(unsigned int iValue);
    
    void clear();
    
    // search
    bool find(unsigned int iValue);
    
    // capacity
    unsigned size() { return treeSize; }
    bool empty() { return treeSize == 0; }
    
    // print
    void print();
};

}