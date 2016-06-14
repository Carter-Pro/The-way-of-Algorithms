#include "BinaryTreeNode.h"

class BinarySearchTree
{
private:
     int size;
     binaryTreeNode *root;
     binaryTreeNode* _search(binaryTreeNode *p, int key);
     binaryTreeNode* _minimum(binaryTreeNode* p);
     binaryTreeNode* _maximum(binaryTreeNode* p);
     binaryTreeNode* _successor(binaryTreeNode *p);
     binaryTreeNode* _predecessor(binaryTreeNode *p);
     void transplant(binaryTreeNode* u, binaryTreeNode *v);
     void _inorderTreeWalk(binaryTreeNode *p);
public:
     BinarySearchTree();
     binaryTreeNode* search(int key);
     binaryTreeNode* minimum();
     binaryTreeNode* maximum();
     binaryTreeNode* successor(int key);
     binaryTreeNode* predecessor(int key);
     void insert(int key, int value);
     void Delete(int key);
     void inorderTreeWalk();
     void Print();
};
