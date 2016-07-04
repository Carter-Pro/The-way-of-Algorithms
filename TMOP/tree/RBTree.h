#ifndef RBTREE_H
#define RBTREE_H

#include "RBNode.h"
class RBTree
{
private:
     int size;
     RBNode *root;
     RBNode *NIL;
     void leftRotate(RBNode *x);
     void rightRotate(RBNode *x);
     void insertFixup(RBNode *z);
     void deleteFixup(RBNode *z);
public:
     RBTree();
     void insert(int key);
     void Delete(int key);
};


#endif /* RBTREE_H */
