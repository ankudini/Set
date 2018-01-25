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
    RedBlackTree();
    
    // copy-constructor
    RedBlackTree(const RedBlackTree& iTree);
    
    // move-constructor
    RedBlackTree(RedBlackTree&& iTree);
    
    // copy-assignment operator
    RedBlackTree& operator=(const RedBlackTree& iTree);
    
    // move-assignment operator
    RedBlackTree& operator=(RedBlackTree&& iTree);
    
    // destructor
    ~RedBlackTree();
    
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