#include "RedBlackTree.h"

#include <iostream>
#include <utility>

namespace CustomContainers {
    
namespace {
 
Node* insertWithoutRebalance(Node* iRoot, Node* iNewNode)
{
    if (iRoot == nullptr)
    {
       return iNewNode;
    }
    
    if (iNewNode->value < iRoot->value)
    {
        iRoot->left = insertWithoutRebalance(iRoot->left, iNewNode);
        iRoot->left->parent = iRoot;
    }
    else if (iNewNode->value > iRoot->value)
    {
        iRoot->right = insertWithoutRebalance(iRoot->right, iNewNode);
        iRoot->right->parent = iRoot;
    }
    return iRoot;
}
 
void rotateLeft(Node*& iRoot, Node*& iNode)
{
    Node *rightNode = iNode->right;
    iNode->right = rightNode->left;
 
    if (iNode->right != nullptr)
    {
        iNode->right->parent = iNode;
    }
    
    rightNode->parent = iNode->parent;
 
    if (iNode->parent == nullptr)
    {
        iRoot = rightNode;
    }
    else if (iNode == iNode->parent->left)
    {
        iNode->parent->left = rightNode;
    }
    else
    {
        iNode->parent->right = rightNode;
    }
    
    rightNode->left = iNode;
    iNode->parent = rightNode;
}
 
void rotateRight(Node*& iRoot, Node*& iNode)
{
    Node *leftNode = iNode->left;
    iNode->left = leftNode->right;
 
    if (iNode->left != nullptr)
    {
        iNode->left->parent = iNode;
    }
    
    leftNode->parent = iNode->parent;
    
    if (iNode->parent == nullptr)
    {
        iRoot = leftNode;
    }
    else if (iNode == iNode->parent->left)
    {
        iNode->parent->left = leftNode;
    }
    else
    {
        iNode->parent->right = leftNode;
    }
    
    leftNode->right = iNode;
    iNode->parent = leftNode;
}
 
void rebalanceAfterInsertion(Node*& iRoot, Node*& iNode)
{
    Node *parent = nullptr;
    Node *grandParent = nullptr;
 
    while ((iNode != iRoot) 
        && (iNode->color != BLACK) 
        && (iNode->parent->color == RED))
    {
        parent = iNode->parent;
        grandParent = iNode->parent->parent;
 
        if (parent == grandParent->left)
        {
            Node* uncle = grandParent->right;
            if (uncle != nullptr && uncle->color == RED)
            {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                iNode = grandParent;
            }
            else
            {
                if (iNode == parent->right)
                {
                    rotateLeft(iRoot, parent);
                    iNode = parent;
                    parent = iNode->parent;
                }
                rotateRight(iRoot, grandParent);
                std::swap(parent->color, grandParent->color);
                iNode = parent;
            }
        }
        else
        {
            Node *uncle = grandParent->left;
            if (uncle != nullptr && uncle->color == RED)
            {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                iNode = grandParent;
            }
            else
            {
                if (iNode == parent->left)
                {
                    rotateRight(iRoot, parent);
                    iNode = parent;
                    parent = iNode->parent;
                }
                rotateLeft(iRoot, grandParent);
                std::swap(parent->color, grandParent->color);
                iNode = parent;
            }
        }
    }
    iRoot->color = BLACK;
} 

// Depth-wise traversal and printing
void printHelper(Node *iNode)
{
    if (iNode == nullptr) return;
 
    printHelper(iNode->left);
    std::cout << iNode->value << "  ";
    printHelper(iNode->right);
}

// Find helper
bool findHelper(Node *iNode, unsigned int iValue)
{
    if (iNode == nullptr) 
    {
        return false;
    } 
    else if (iNode->value == iValue) 
    {
        return true;
    } 
    else
    {
        return findHelper(iValue < iNode->value ? iNode->left : iNode->right, iValue);
    }
}

}

bool RedBlackTree::insert(unsigned int iValue)
{
    if ( find(iValue) ) return false; // TODO: This step can be skipped if proper changes are done to insertion
    
    Node* newNode = new Node(iValue);
 
    // do a normal insertion without rebalancing
    root = insertWithoutRebalance(root, newNode);
 
    // rebalance
    rebalanceAfterInsertion(root, newNode);
    
    ++treeSize;
}

bool RedBlackTree::erase(unsigned int iValue)
{
    // TODO: Make implementation of this function. 
    //       This should be split into eraseWithoutRebalance and rebalanceAfterErase functions as done with insertion.
}
    
void RedBlackTree::clear()
{
    delete(root);
}
    
bool RedBlackTree::find(unsigned int iValue)
{
    return findHelper(root, iValue);
}

void RedBlackTree::print()
{
    printHelper(root);
}

}