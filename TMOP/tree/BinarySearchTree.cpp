#include <iostream>
#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree() {
     this->root = nullptr;
     this->size = 0;
}


binaryTreeNode* BinarySearchTree::search(int key) {
     return _search(root, key);
}


binaryTreeNode* BinarySearchTree::_search(binaryTreeNode* p, int key) {
     while (p != nullptr && p->key != key) {
          if (key < p->key)
               p = p->left;
          else
               p = p->right;
     }
     return p;
     // recursion
     // if (p == nullptr || p->key == key)
     //      return p;

     // if (key < p->key)
     //      return _search(p->left, key);
     // else
     //      return _search(p->right, key);
}


binaryTreeNode* BinarySearchTree::minimum() {
     return _minimum(root);
}


binaryTreeNode* BinarySearchTree::_minimum(binaryTreeNode* p) {
     while(p->left != nullptr)
          p = p->left;
     return p;
}

binaryTreeNode* BinarySearchTree::maximum() {
     return _maximum(root);
}

binaryTreeNode* BinarySearchTree::_maximum(binaryTreeNode* p) {
     while(p->right != nullptr)
          p = p->left;
     return p;
}

binaryTreeNode* BinarySearchTree::successor(int key) {
     binaryTreeNode *p = search(key);
     return _successor(p);
}


binaryTreeNode* BinarySearchTree::_successor(binaryTreeNode* p) {
     if (p->right != nullptr)
          return _minimum(p->right);
     // attention p right maybe null, and we should find the node
     // which is the left node of its parents.
     binaryTreeNode* y = p->parent;
     while (y != nullptr && p == y->right) {
          p = y;
          y = y->parent;
     }

     return y;
}


binaryTreeNode* BinarySearchTree::predecessor(int key) {
     return _predecessor(search(key));
}


binaryTreeNode* BinarySearchTree::_predecessor(binaryTreeNode* p) {
     if (p->left != nullptr)
          return _maximum(p->left);
     binaryTreeNode* y = p->parent;
     while (y != nullptr && p == y->left) {
          p = y;
          y = y->parent;
     }

     return y;
}

void BinarySearchTree::insert(int key, int value) {
     if (root == nullptr) {
          root = new binaryTreeNode(key, value);
          return;
     }

     binaryTreeNode* z = new binaryTreeNode(key, value);
     binaryTreeNode* x = root;
     binaryTreeNode* y = nullptr;

     while (x != nullptr) {
          y = x;
          if (z->key < x->key)
               x = x->left;
          else
               x = x->right;
     }
     z->parent = y;
     if (z->key < y->key)
          y->left = z;
     else
          y->right = z;
}


void BinarySearchTree::transplant(binaryTreeNode* u, binaryTreeNode* v) {
     if (u->parent == nullptr)
          root = v;
     else if (u->parent->left == u)
          u->parent->left = v;
     else
          u->parent->right = v;

     if (v != nullptr)
          v->parent = u->parent;
}

void BinarySearchTree::Delete(int key) {
     binaryTreeNode* z = search(key);
     if (z == nullptr)
          return;
     if (z->left == nullptr)
          transplant(z, z->right);
     else if (z->right == nullptr)
          transplant(z, z->left);
     else {
          binaryTreeNode* y = _minimum(z->right);
          if (y != z->right) {
               transplant(y, y->right);
               y->right = z->right;
               z->right->parent = y;
          }
          transplant(z, y);
          y->left = z->left;
          y->left->parent = y;
     }
}



void BinarySearchTree::_inorderTreeWalk(binaryTreeNode* p) {
     if (p == nullptr)
          return;

     _inorderTreeWalk(p->left);
     std::cout << p->key << " ";
     _inorderTreeWalk(p->right);

}

void BinarySearchTree::inorderTreeWalk() {
     binaryTreeNode* p = root;
     _inorderTreeWalk(p);
     std::cout << std::endl;
}

void BinarySearchTree::Print() {
     
}
