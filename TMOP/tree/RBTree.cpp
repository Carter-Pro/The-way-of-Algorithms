#include "RBTree.h"


RBTree::RBTree() {
     size = 0;
     root = nullptr;
     NIL = new RBNode(0);
     NIL->color = BLACK;
}

void RBTree::rightRotate(RBNode *x) {
     //clockwise rotation
     RBNode *y = x->left;
     if (y == nullptr)
          return;
     // 1.
     x->left = y->right;
     if (y->right != nullptr)
          y->right->parent = x;

     // 2.
     if (x->parent == nullptr)
          root = y;
     else if (x->parent->left == x)
          x->parent->left = y;
     else
          x->parent->right = y;
     y->parent = x->parent;
     // 3.
     y->right = x;
     x->parent = y;
}

void RBTree::leftRotate(RBNode *x) {
     // contrarotate
     RBNode *y = x->right;
     if (y == nullptr)
          return;
     // 1. make x right points to y left
     x->right = y->left;
     if (y->left != nullptr)
          x->right->parent = x;

     // 2. x parent point to y
     y->parent = x->parent;
     if (x->parent == nullptr)
          root = y;
     else if (x->parent->left == x)
          x->parent->left = y;
     else
          x->parent->right = y;

     // 3. make y left points to x
     y->left = x;
     x->parent = y;
}


void RBTree::insertFixup(RBNode* z) {
     while (z->parent->color == RED) {
          if (z->parent == z->parent->parent->left) {
               RBNode *y = z->parent->parent->right;
               if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    y->parent->color = RED;
                    z = z->parent->parent;
               } else {
                    if (z = z->parent->right) {
                         z = z->parent;
                         leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
               }
          } else {
               RBNode *y = z->parent->parent->left;
               if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    y->parent = RED;
                    z = z->parent->parent;
               } else {
                    if (y == y->parent->left) {
                         z = z->parent;
                         rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
               }
          }
     }
     root->color = BLACK;
}


void RBTree::insert(int key) {
     RBNode *z = new RBNode(key);
     RBNode *x = root;
     RBNode *y = NIL;

     while (x != NIL) {
          y = x;
          if (key < x->key)
               x = x->left;
          else
               x = x->right;
     }
     z->parent = y;

     if (y == NIL)
          root = z;
     else if (key < y->key)
          y->left = z;
     else
          y->right = z;
     z->left = NIL;
     z->right = NIL;
     z->color = RED;
     insertFixup(z);
}
